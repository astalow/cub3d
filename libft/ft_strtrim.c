#include "libft.h"

static int	check_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!set || !s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (check_set(s1[i], set))
		i++;
	while (check_set(s1[len - 1], set) && len)
	{
		if (i == len)
			return (ft_strdup(""));
		len--;
	}
	str = ft_substr(s1, i, len - i);
	if (!str)
		return (NULL);
	return (str);
}
