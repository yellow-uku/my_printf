/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alina <alina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 20:24:15 by pkayleen          #+#    #+#             */
/*   Updated: 2021/05/04 09:44:28 by alina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# include "ft_printf.h"

void	type_c(t_struct *types);
void	type_s(t_struct *types);
char	*type_p(t_struct *types);
char	*type_x(t_struct *types);
char	*type_upper_x(t_struct *types);
void	type_u(t_struct *types);
void	type_d_i(t_struct *types);

#endif
