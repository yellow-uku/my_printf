/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:45:44 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/21 16:14:21 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include "ft_parser.h"
# include "ft_types.h"
# include "../libft/libft.h"

int			ft_printf(const char *input, ...);
int			if_neg(unsigned long long *num, char *s, long int *len);
long int	count_num_u(unsigned long long num);
long int	power(long int num, long int p);
char		*ft_itoa_u(unsigned long long n);
int			if_neg_num(t_struct *format, int num, int *len);
void		put_num(t_struct *format, int num);
void		put_zero(t_struct *format, int diff);
void		put_str(t_struct *format, char *str);

#endif
