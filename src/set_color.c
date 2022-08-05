#include "cub3d.h"

void	check_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			exit_error(CUB_FORMAT_ERROR);
		i++;
	}
}

bool	is_three_elem(char	**rgb)
{
	int	i;

	if (rgb == NULL)
		return (false);
	i = 0;
	while (rgb[i] != NULL)
	{
		if (ft_strlen(rgb[i]) > 3)
			return (false);
		check_number(rgb[i]);
		i++;
	}
	if (i == 3)
		return (true);
	return (false);
}

static t_rgb	get_rgb(char *line)
{
	int		len;
	t_rgb	rgb;
	char	*str_rgb;
	char	**split_rgb;

	len = ft_strlen(line);
	str_rgb = ft_substr(line, C_PREFIX_SIZE, len - C_PREFIX_SIZE);
	split_rgb = ft_split(str_rgb, ',');
	if (!is_three_elem(split_rgb))
		exit_error(CUB_FORMAT_ERROR);
	rgb.red = ft_atoi(split_rgb[0]);
	rgb.green = ft_atoi(split_rgb[1]);
	rgb.blue = ft_atoi(split_rgb[2]);
	free(split_rgb[0]);
	free(split_rgb[1]);
	free(split_rgb[2]);
	free(split_rgb);
	free(str_rgb);
	return (rgb);
}

t_rgb	get_color(char *line)
{
	t_rgb	rgb;

	rgb = get_rgb(line);
	rgb.code = rgb.red << 16;
	rgb.code |= rgb.green << 8;
	rgb.code |= rgb.blue;
	return (rgb);
}
