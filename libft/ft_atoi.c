#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	i;
	long long int	num;
	long long int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\t') ||
			(str[i] == '\r') || (str[i] == '\n') ||
			(str[i] == '\v') || (str[i] == '\f'))
	{
		i++;
	}
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
