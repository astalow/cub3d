#include "cub3d.h"

char	*get_texture_path(char *line)
{
	size_t	len;
	char	*texture_path;

	len = ft_strlen(line);
	texture_path = ft_substr(line, T_PREFIX_SIZE, len - T_PREFIX_SIZE);
	return (texture_path);
}
