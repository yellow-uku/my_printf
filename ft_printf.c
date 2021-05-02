/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:45:59 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/21 16:15:59 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *input, ...)
{
	t_struct	f[1];
	int			i;

	i = 0;
	f->len = 0;
	va_start(f->args, input);
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1] != '\0')
			i += parsing(f, input + i + 1);
		else
		{
			write(1, &(input[i]), 1);
			f->len++;
			i++;
		}
	}
	va_end(f->args);
	return (f->len);
}
