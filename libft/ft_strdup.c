#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t			i;
	size_t			len;
	unsigned char	*dup;
	unsigned char	*p;

	len = ft_strlen(src);
	p = (unsigned char *)src;
	dup = (unsigned char *)x_malloc(sizeof(unsigned char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (p[i])
	{
		dup[i] = p[i];
		i++;
	}
	dup[i] = '\0';
	return ((char *)dup);
}
