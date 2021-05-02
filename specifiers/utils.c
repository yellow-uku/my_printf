/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:49:46 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/21 16:15:49 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		initial_args(t_struct *f)
{
	f->width = 0;
	f->precision = -1;
	f->minus = 0;
	f->zero = 0;
}

int			if_neg(unsigned long long *num, char *s, long int *len)
{
	if (*num < 0)
	{
		*num *= -1;
		s[0] = '-';
		*len = *len - 1;
		return (1);
	}
	else
		return (0);
}

long int	count_num_u(unsigned long long num)
{
	long int	count;

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

long int	power(long int num, long int p)
{
	long int	res;

	if (p == 0)
		res = 1;
	else
		res = num * power(num, p - 1);
	return (res);
}

char		*ft_itoa_u(unsigned long long n)
{
	char				*str;
	long int			len;
	long int			i;
	unsigned long long	d;
	unsigned long long	num;

	num = n;
	len = count_num_u(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = if_neg(&num, str, &len);
	while (len != 0)
	{
		d = num / (power(10, len - 1));
		str[i++] = d + '0';
		num = num - d * (power(10, len - 1));
		len--;
	}
	str[i] = '\0';
	return (str);
}
