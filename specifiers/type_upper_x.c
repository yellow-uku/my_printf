#include "../includes/ft_printf.h"

static void	precision_int(t_struct *format, char *str, int len)
{
	int diff;
	int	i;

	diff = 0;
	if (format->precision > len)
		diff = format->precision - len;
	else if (format->precision == -1 && (format->zero))
		diff = format->width - len;
	while (diff > 0)
	{
		write(1, "0", 1);
		format->len++;
		diff--;
	}
	i = 0;
	while (str[i])
	{
		write(1, &(str[i++]), 1);
		format->len++;
	}
}

static void	put_space_int(t_struct *format, int len)
{
	int	diff2;

	diff2 = 0;
	if (format->width > format->precision)
	{
		if (format->precision < len)
			diff2 = format->width - len;
		else
			diff2 = format->width - format->precision;
	}
	while (diff2 > 0)
	{
		write(1, " ", 1);
		format->len++;
		diff2--;
	}
}

static char	*check_flags_x(t_struct *format, char *output, int *output_len)
{
	if (format->minus)
	{
		precision_int(format, output, *output_len);
		put_space_int(format, *output_len);
	}
	else
	{
		if (!format->zero
			|| ((format->zero) && (format->precision >= 0)))
			put_space_int(format, *output_len);
		precision_int(format, output, *output_len);
	}
	return (output);
}

static int	check_zero(t_struct *format, int num, int len)
{
	char	*str_num;

	str_num = NULL;
	if (num != 0)
		return (1);
	else
	{
		if (format->precision != 0)
		{
			str_num = "0";
			str_num = check_flags_x(format, str_num, &len);
		}
		else
			put_space_int(format, len - 1);
	}
	return (0);
}

char		*type_upper_x(t_struct *format)
{
	unsigned int	num;
	int				output_len;
	char			*output;

	format->upper_x = va_arg(format->args, int);
	num = (unsigned int)format->upper_x;
	output_len = ft_len_turn_to_16(num);
	output = NULL;
	if (!(format->upper_x))
		output = "";
	if (check_zero(format, num, output_len))
	{
		if (!(output = (char *)malloc(output_len + 1)))
			return (NULL);
		output[output_len] = '\0';
		ft_turn_to_16_upper(num, output);
		output = check_flags_x(format, output, &output_len);
	}
	if (format->upper_x)
		free(output);
	return (output);
}
