#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!s2[0])
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j] && i + j < n)
		{
			if (!s2[j + 1])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
