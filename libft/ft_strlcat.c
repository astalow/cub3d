#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = dst_len;
	if (dst_len < size && size)
	{
		while (src[i] && (dst_len + i) < (size - 1))
			dst[j++] = src[i++];
		dst[j] = '\0';
		return (dst_len + src_len);
	}
	return (src_len + size);
}
