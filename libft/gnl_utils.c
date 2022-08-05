#include "libft.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	u_c;

	if (!s)
		return (NULL);
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

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	unsigned char	*join;
	size_t			i;
	size_t			j;

	j = 0;
	i = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2)
		return (NULL);
	join = (unsigned char *)x_malloc(sizeof(unsigned char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
		join[j++] = (unsigned char)s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = (unsigned char)s2[i++];
	join[j] = '\0';
	free(s1);
	return ((char *)join);
}
