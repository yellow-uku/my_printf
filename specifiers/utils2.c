/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:55:59 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/21 16:15:55 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_str(t_struct *format, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &(str[i++]), 1);
		format->len++;
	}
}

void	put_zero(t_struct *format, int diff)
{
	while (diff > 0)
	{
		write(1, "0", 1);
		format->len++;
		diff--;
	}
}

void	put_num(t_struct *format, int num)
{
	char	*str_num;

	str_num = ft_itoa(num);
	put_str(format, str_num);
	free(str_num);
}

int		if_neg_num(t_struct *format, int num, int *len)
{
	if ((num < 0) && (num != -2147483648))
	{
		write(1, "-", 1);
		num = num * (-1);
		format->len++;
		(*len)--;
	}
	else if (num == -2147483648)
		(*len)--;
	return (num);
}
