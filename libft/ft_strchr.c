#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	u_c;

	str = (unsigned char *)s;
	u_c = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == u_c)
			break ;
		i++;
	}
	if (str[i] == u_c)
		return ((char *)&str[i]);
	return (NULL);
}

int	ft_strchr_n(char *s, char c)
{
	char	*p;

	if (!s)
		return (-1);
	p = ft_strchr(s, c);
	if (!p)
		return (-1);
	return (p - s);
}
