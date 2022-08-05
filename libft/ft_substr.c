#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	str_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	str_len = s_len - (size_t)start;
	if (str_len > len)
		str_len = len;
	str = (char *)x_malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, str_len + 1);
	return (str);
}
