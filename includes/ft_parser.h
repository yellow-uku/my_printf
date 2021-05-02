/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkayleen <pkayleen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:45:55 by pkayleen          #+#    #+#             */
/*   Updated: 2021/03/21 16:13:51 by pkayleen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdarg.h>
# define ALL_SPECIFIERS "cspdiouxX-.*0123456789"

typedef struct	s_struct
{
	int			len;
	int			minus;
	int			zero;
	int			width;
	int			precision;
	char		c;
	char		*s;
	void		*p;
	int			x;
	int			upper_x;
	int			u;
	int			d;
	va_list		args;
}				t_struct;

int				parsing(t_struct *f, const char *input);
int				parsing2(t_struct *format, const char *input, int i);
void			initial_args(t_struct *f);

#endif
