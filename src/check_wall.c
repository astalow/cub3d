#include "cub3d.h"

bool	is_valid_position(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	get_position(char **map, char *c, t_position *position)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (is_valid_position(map[i][j]))
			{
				*c = map[i][j];
				position->x = j;
				position->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	*c = ' ';
	return ;
}

void	flood_fill(char **map, t_position p, int max_y, char new_color)
{
	int	max_x;

	max_x = ft_strlen(map[p.y]);
	if (p.x < 0 || p.y < 0 || p.x >= max_x || p.y >= max_y)
		return ;
	if (map[p.y][p.x] == new_color)
		return ;
	if (!is_valid_position(map[p.y][p.x]))
	{
		if (map[p.y][p.x] == '1')
			return ;
		else
			exit_error(WALL_ERROR);
	}
	map[p.y][p.x] = new_color;
	flood_fill(map, p, max_y, new_color);
	flood_fill(map, p, max_y, new_color);
	flood_fill(map, p, max_y, new_color);
	flood_fill(map, p, max_y, new_color);
}

void	check_valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!(map[i][j] == ' ' || map[i][j] == '1' || map[i][j] == '#'))
				exit_error(MAP_INVALID_ERROR);
			j++;
		}
		i++;
	}
}

void	check_wall(t_game_data *gd)
{
	char		**map;
	char		c;
	t_position	position;
	int			max_y;

	map = dupmap(gd->map);
	max_y = get_line_size(map);
	while (true)
	{
		get_position(map, &c, &position);
		if (c == ' ')
			break ;
		flood_fill(map, position, max_y, '#');
	}
	check_valid_map(map);
	free_map(map);
}
