#include "cub3d.h"

void	free_mlx(t_game_data *data)
{
	if (data->mlx)
	{
		if (data->imgs.wall_east.ptr)
			mlx_destroy_image(data->mlx, data->imgs.wall_east.ptr);
		if (data->imgs.wall_north.ptr)
			mlx_destroy_image(data->mlx, data->imgs.wall_north.ptr);
		if (data->imgs.wall_south.ptr)
			mlx_destroy_image(data->mlx, data->imgs.wall_south.ptr);
		if (data->imgs.wall_west.ptr)
			mlx_destroy_image(data->mlx, data->imgs.wall_west.ptr);
		if (data->imgs.door.ptr)
			mlx_destroy_image(data->mlx, data->imgs.door.ptr);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		if (data->map_img_data.ptr)
			mlx_destroy_image(data->mlx, data->map_img_data.ptr);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	free_cell(t_game_data *data)
{
	size_t	i;

	i = 0;
	if (data->map2)
	{
		while (i < data->rows)
		{
			if (data->map2[i])
				free(data->map2[i]);
			i++;
		}
		free(data->map2);
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all(t_game_data *data)
{
	if (data->tp.no_path)
		free(data->tp.no_path);
	if (data->tp.ea_path)
		free(data->tp.ea_path);
	if (data->tp.so_path)
		free(data->tp.so_path);
	if (data->tp.we_path)
		free(data->tp.we_path);
	free_cell(data);
	free_map(data->map);
	if (data->fov)
		free(data->fov);
	free_mlx(data);
}

void	free_exit(t_game_data *data, char *msg)
{
	free_all(data);
	exit_error(msg);
}
