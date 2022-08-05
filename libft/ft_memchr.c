#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*u_s;
	unsigned char	u_c;

	u_s = (unsigned char *)s;
	u_c = (unsigned char)c;
	while (n--)
	{
		if (*u_s == u_c)
			return ((void *)u_s);
		u_s++;
	}
	return (NULL);
}
