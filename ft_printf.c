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
