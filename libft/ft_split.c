#include "libft.h"

static size_t	ft_check_sep(char *s,	char c)
{
	size_t	i;
	size_t	count;
	int		sep_flg;

	i = 0;
	sep_flg = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			sep_flg = 1;
		else if (s[i] != c && sep_flg == 1)
		{
			sep_flg = 0;
			count++;
		}
		else if (s[i] != c)
			sep_flg = 0;
		i++;
	}
	return (count);
}

static void	all_free(char **rtn, size_t size)
{
	while (size > 0)
		free(rtn[size--]);
	free(rtn[0]);
	free(rtn);
}

static char	**ft_cpy(char *s, char **rtn, char c, size_t sep)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (k < sep)
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] != c && s[i + j])
			j++;
		rtn[k] = ft_substr(s, i, j);
		if (!rtn[k])
		{
			all_free(rtn, k);
			return (NULL);
		}
		i += j;
		k += 1;
	}
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	size_t	sep;

	if (!s)
		return (NULL);
	sep = ft_check_sep((char *)s, c);
	rtn = (char **)x_malloc(sizeof(char *) * (sep + 1));
	if (!rtn)
		return (NULL);
	rtn = ft_cpy((char *)s, rtn, c, sep);
	if (!rtn)
		return (NULL);
	rtn[sep] = NULL;
	return (rtn);
}
