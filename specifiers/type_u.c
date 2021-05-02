/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:04:06 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/21 16:15:35 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		check_flags_u(t_struct *format, char *str_num, int *len)
{
	if (format->minus)
	{
		precision_int(format, str_num, *len);
		put_space_int(format, *len);
	}
	else
	{
		if (!format->zero || ((format->zero) && (format->precision >= 0)))
			put_space_int(format, *len);
		precision_int(format, str_num, *len);
	}
}

static int	check_zero(t_struct *format, unsigned long long int num, int len)
{
	char	*str_num;

	if (num != 0)
		return (1);
	else
	{
		if (format->precision != 0)
		{
			str_num = "0";
			check_flags_u(format, str_num, &len);
		}
		else
			put_space_int(format, len - 1);
	}
	return (0);
}

void		type_u(t_struct *format)
{
	unsigned long long	num;
	char				*str_num;
	int					len;

	num = va_arg(format->args, unsigned int);
	str_num = ft_itoa_u(num);
	len = ft_strlen(str_num);
	if (check_zero(format, num, len))
		check_flags_u(format, str_num, &len);
	free(str_num);
}
