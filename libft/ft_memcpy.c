#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_new;
	char	*src_new;
	size_t	i;

	dst_new = (char *)dst;
	src_new = (char *)src;
	if (!dst_new && !src_new)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst_new[i] = src_new[i];
		i++;
	}
	return (dst);
}
