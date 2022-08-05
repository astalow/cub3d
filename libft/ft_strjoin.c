#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*join;
	size_t			i;
	size_t			j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	join = (unsigned char *)ft_calloc(1, sizeof(unsigned char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[i])
		join[j++] = (unsigned char)s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = (unsigned char)s2[i++];
	join[j] = '\0';
	return ((char *)join);
}

char	*ft_strjoin_and_free(char **s1, char **s2)
{
	char	*rtn;

	rtn = ft_strjoin(*s1, *s2);
	free(*s1);
	*s1 = NULL;
	free(*s2);
	*s2 = NULL;
	return (rtn);
}
