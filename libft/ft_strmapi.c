#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	size_t	i;

	if (!s || !f)
		return (NULL);
	rtn = (char *)x_malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rtn[i] = (*f)(i, s[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
