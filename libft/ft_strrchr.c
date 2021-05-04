#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		res;
	int		i;

	i = 0;
	res = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			res = i;
		i++;
	}
	if (s[i] == c)
		res = i;
	if (res == -1)
		return (NULL);
	return ((char *)(s + res));
}
