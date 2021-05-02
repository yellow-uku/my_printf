/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn_to_16_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 22:19:41 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/09 22:29:10 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_turn_to_16_upper(size_t num, char *output)
{
	int	reminder;
	int	i;

	reminder = 0;
	i = ft_len_turn_to_16(num) - 1;
	while (num)
	{
		reminder = num % 16;
		if (reminder >= 10)
			output[i] = 'A' + (reminder - 10);
		else
			output[i] = reminder + '0';
		num /= 16;
		i--;
	}
	return (output);
}
