#include "cub3d.h"

void	debug_set_map(char ***m)
{
	int			i;
	int			j;
	const char	map[11][8] = {
	{'1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '1', '1', '1', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1'}
	};

	i = 0;
	*m = malloc(sizeof(char *) * (11 + 1));
	while (i < 11)
	{
		j = 0;
		(*m)[i] = malloc(sizeof(char) * 8 + 1);
		while (j < 8)
		{
			(*m)[i][j] = map[i][j];
			j++;
		}
		(*m)[i][j] = '\0';
		i++;
	}
	(*m)[i] = NULL;
}

void	print_map_data(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		printf("{");
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			if (map[i][j + 1])
				printf(", ");
			j++;
		}
		printf("}\n");
		i++;
	}
	printf("\n");
}

void	print_cell_data(t_cell **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		printf("{");
		while (j < cols)
		{
			printf("%c", map[i][j].type);
			if (j + 1 < cols)
				printf(", ");
			j++;
		}
		printf("}\n");
		i++;
	}
	printf("\n");
}

void	debug_set_color(t_game_data *data)
{
	data->floor_color.red = 0;
	data->floor_color.green = 0;
	data->floor_color.blue = 0xFF;
	data->floor_color.code = 0x0000FF;
	data->ceiling_color.red = 0;
	data->ceiling_color.green = 0xFF;
	data->ceiling_color.blue = 0;
	data->ceiling_color.code = 0x00FF00;
}

void	debug_set_texpath(t_game_data *data)
{
	data->tp.no_path = ft_strdup("./maps/texture/wall_north.xpm");
	data->tp.so_path = ft_strdup("./maps/texture/wall_south.xpm");
	data->tp.ea_path = ft_strdup("./maps/texture/wall_east.xpm");
	data->tp.we_path = ft_strdup("./maps/texture/wall_west.xpm");
}
