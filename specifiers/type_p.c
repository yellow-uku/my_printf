/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:21:25 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/21 16:15:32 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_space(t_struct *format, int len)
{
	int	diff;

	diff = 0;
	if (format->width > len)
		diff = format->width - len;
	while (diff)
	{
		write(1, " ", 1);
		format->len++;
		diff--;
	}
}

void	check_flags_p(t_struct *format, char *output, int len)
{
	if (format->minus)
	{
		write(1, output, len);
		put_space(format, len);
	}
	else
	{
		put_space(format, len);
		write(1, output, len);
	}
}

char	*null_p(t_struct *format, char *output, int *len)
{
	if (!(format->p) || (format->p == NULL))
	{
		if (format->precision != 0)
		{
			output = "0x0";
			format->len += 3;
			*len = 3;
		}
		else
		{
			output = "0x";
			format->len += 2;
			*len = 2;
		}
	}
	return (output);
}

char	*type_p(t_struct *format)
{
	char					*output;
	int						output_len;
	size_t					num;

	format->p = va_arg(format->args, void*);
	output = NULL;
	output_len = 0;
	output = null_p(format, output, &output_len);
	if (!(output))
	{
		num = (size_t)(format->p);
		output_len = ft_len_turn_to_16(num);
		if (!(output = (char *)malloc(output_len + 3)))
			return (NULL);
		output[0] = '0';
		output[1] = 'x';
		output_len += 2;
		output[output_len] = '\0';
		ft_turn_to_16(num, &(output[2]));
		format->len += output_len;
	}
	check_flags_p(format, output, output_len);
	if (format->p)
		free(output);
	return (output);
}
