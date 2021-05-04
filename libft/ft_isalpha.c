#include "libft.h"

int	ft_isalpha(int letter)
{
	if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
	{
		return (1);
	}
	else
		return (0);
}
