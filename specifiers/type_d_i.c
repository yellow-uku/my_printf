#include "../includes/ft_printf.h"

static int	precision_int(t_struct *format, int num, int len)
{
	int	diff;

	diff = 0;
	if (format->precision >= len)
	{
		num = if_neg_num(format, num, &len);
		diff = format->precision - len;
	}
	else if ((format->precision == -1) && (format->zero) && (!format->minus))
	{
		diff = format->width - len;
		num = if_neg_num(format, num, &len);
	}
	else
		num = if_neg_num(format, num, &len);
	put_zero(format, diff);
	put_num(format, num);
	return (len);
}

static void	put_space_int(t_struct *format, int len, int num)
{
	int		diff2;

	diff2 = 0;
	if (format->width >= format->precision)
	{
		if (format->precision < len)
		{
			diff2 = format->width - len;
		}
		else if (format->precision != -1)
		{
			diff2 = format->width - format->precision;
			if ((num < 0) && (format->precision > 0))
				diff2--;
		}
	}
	while (diff2 > 0)
	{
		write(1, " ", 1);
		format->len++;
		diff2--;
	}
}

int			check_zero(t_struct *format, int num, int len)
{
	if (num != 0)
		return (1);
	else
	{
		if (format->precision != 0)
		{
			if (format->minus)
			{
				precision_int(format, num, len);
				put_space_int(format, len, num);
			}
			else
			{
				if (!format->zero
					|| ((format->zero) && (format->precision >= 0)))
					put_space_int(format, len, num);
				precision_int(format, num, len);
			}
		}
		else
			put_space_int(format, len - 1, num);
	}
	return (0);
}

static int	count_num(long long int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		num *= -1;
		count++;
	}
	while (num >= 10)
	{
		num = num / 10;
		count++;
	}
	count++;
	return (count);
}

void		type_d_i(t_struct *format)
{
	int				len;
	long long int	num;

	num = va_arg(format->args, int);
	len = count_num(num);
	if (check_zero(format, num, len))
	{
		if (format->minus)
		{
			precision_int(format, num, len);
			put_space_int(format, len, num);
		}
		else
		{
			if (!format->zero
				|| ((format->zero) && (format->precision >= 0)))
				put_space_int(format, len, num);
			precision_int(format, num, len);
		}
	}
}
