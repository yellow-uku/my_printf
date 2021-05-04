#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	subs = (char *)malloc(len + 1);
	if (!s || !subs)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		subs[i] = '\0';
		return (subs);
	}
	while (i != start)
		i++;
	j = 0;
	while (j != len && s[i] != '\0')
	{
		subs[j] = s[i];
		i++;
		j++;
	}
	subs[j] = '\0';
	return (subs);
}
