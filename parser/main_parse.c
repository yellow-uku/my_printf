#include "../includes/ft_printf.h"

void	check_types(t_struct *f, const char *input)
{
	if (*input == 'c')
		type_c(f);
	else if (*input == 's')
		type_s(f);
	else if (*input == 'p')
		type_p(f);
	else if (*input == 'x')
		type_x(f);
	else if (*input == 'X')
		type_upper_x(f);
	else if (*input == 'u')
		type_u(f);
	else if (*input == 'd' || *input == 'i')
		type_d_i(f);
}

int		parsing(t_struct *f, const char *input)
{
	int	i;

	i = 0;
	if (input[i] == '%')
	{
		write(1, "%", 1);
		f->len++;
		i += 2;
		return (i);
	}
	if (!ft_strchr(ALL_SPECIFIERS, *input))
		return (0);
	initial_args(f);
	while (ft_strchr(ALL_SPECIFIERS, input[i]))
	{
		if (ft_strchr("cspudixX", input[i]))
		{
			check_types(f, &(input[i]));
			i += 2;
			break ;
		}
		else if (!ft_strchr("cspudixX", input[i]))
			i = parsing2(f, input, i);
	}
	return (i);
}
