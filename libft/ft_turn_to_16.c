/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_to_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:43:57 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/01 20:44:07 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_turn_to_16(size_t i)
{
	int	output_len;

	output_len = 0;
	if (!i)
		return (1);
	while (i)
	{
		i /= 16;
		output_len++;
	}
	return (output_len);
}

char	*ft_turn_to_16(size_t num, char *output)
{
	int				reminder;
	int				i;

	reminder = 0;
	i = ft_len_turn_to_16(num) - 1;
	while (num)
	{
		reminder = num % 16;
		if (reminder >= 10)
			output[i] = 'a' + (reminder - 10);
		else
			output[i] = reminder + '0';
		num /= 16;
		i--;
	}
	return (output);
}
