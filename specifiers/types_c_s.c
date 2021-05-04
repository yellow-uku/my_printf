#include "../includes/ft_printf.h"

void	put_space_str(t_struct *format, int len)
{
	int	diff;

	diff = 0;
	if (format->width > len
		&& ((len < format->precision) || (format->precision == -1)))
		diff = format->width - len;
	else if (((format->width > format->precision) && format->precision != -1)
			|| (format->precision == 0))
		diff = format->width - format->precision;
	while (diff > 0)
	{
		write(1, " ", 1);
		format->len++;
		diff--;
	}
}

void	put_space_c(t_struct *format)
{
	int	diff;

	diff = 0;
	diff = --format->width;
	while (diff > 0)
	{
		format->len++;
		write(1, " ", 1);
		diff--;
	}
}

void	precision_str(t_struct *format, char *str, int len)
{
	int	i;

	if (format->precision < len)
	{
		i = 0;
		while (str[i] && (i != format->precision))
		{
			write(1, &(str[i]), 1);
			format->len++;
			i++;
		}
	}
	else
	{
		write(1, str, len);
		format->len += len;
	}
}

void	type_c(t_struct *format)
{
	int	diff;

	format->c = va_arg(format->args, int);
	diff = 0;
	if (format->minus)
	{
		write(1, &(format->c), 1);
		put_space_c(format);
	}
	else
	{
		put_space_c(format);
		write(1, &(format->c), 1);
	}
	format->len++;
}

void	type_s(t_struct *format)
{
	int	len;

	format->s = va_arg(format->args, char *);
	if (format->s == NULL)
		format->s = "(null)";
	len = ft_strlen(format->s);
	if (format->minus)
	{
		precision_str(format, format->s, len);
		put_space_str(format, len);
	}
	else
	{
		put_space_str(format, len);
		precision_str(format, format->s, len);
	}
}
