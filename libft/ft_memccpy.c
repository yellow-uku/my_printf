#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_n;
	unsigned char	*dst_n;

	src_n = (unsigned char *)src;
	dst_n = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst_n[i] = src_n[i];
		if (src_n[i] == (unsigned char)c)
			return (&dst_n[i + 1]);
		i++;
	}
	return (NULL);
}
