#include "../includes/ft_printf.h"

int	parse_flags(t_struct *flags, const char *input)
{
	int	i;

	i = 0;
	while (input[i] && (input[i] == '0' || input[i] == '-'))
	{
		if (input[i] == '0')
			flags->zero = 1;
		if (input[i] == '-')
			flags->minus = 1;
		i++;
	}
	return (i);
}

int	parse_width(t_struct *flags, const char *input, int i)
{
	if (input[i])
	{
		if (input[i] == '*')
		{
			flags->width = va_arg(flags->args, int);
			if (flags->width < 0)
			{
				flags->minus = 1;
				flags->width *= -1;
			}
			i++;
		}
		else
			while (input[i] && (input[i] >= '0' && input[i] <= '9'))
			{
				flags->width = flags->width * 10 + (input[i] - '0');
				i++;
			}
	}
	return (i);
}

int	parse_precision(t_struct *format, const char *input, int i)
{
	if (input[i] && input[i] == '.')
	{
		i++;
		if (input[i] == '*')
		{
			format->precision = va_arg(format->args, int);
			if (format->precision < 0)
				format->precision = -1;
			i++;
		}
		else
		{
			format->precision = 0;
			while (input[i] && (input[i] >= '0' && input[i] <= '9'))
			{
				format->precision = format->precision * 10 + (input[i] - '0');
				i++;
			}
		}
	}
	return (i);
}

int	parsing2(t_struct *format, const char *input, int i)
{
	i = parse_flags(format, &(input[i]));
	i = parse_width(format, input, i);
	i = parse_precision(format, input, i);
	return (i);
}
