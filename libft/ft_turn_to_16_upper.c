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
