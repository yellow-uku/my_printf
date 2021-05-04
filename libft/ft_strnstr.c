#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *sb, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	hay = (char *)haystack;
	if (ft_strlen(sb) == 0)
		return (hay);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		if (hay[i] == sb[j])
		{
			while ((i + j) < len && j < ft_strlen(sb) && (hay[i + j] == sb[j]))
				j++;
			if (j == ft_strlen(sb))
				return (hay + i);
		}
		i++;
	}
	return (NULL);
}
