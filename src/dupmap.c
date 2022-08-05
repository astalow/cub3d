#include "cub3d.h"

int	get_line_size(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		i++;
	}
	return (i);
}

char	**dupmap(char **map)
{
	char	**dup;
	int		line_size;
	int		i;

	line_size = get_line_size(map);
	dup = (char **)x_malloc(sizeof(char *) * (line_size + 1));
	i = 0;
	while (i < line_size)
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
