#include "cub3d.h"

void	is_initialized_texture_path(t_texture_path tp)
{
	if (tp.no_path == NULL)
		exit_error(PATH_INIT_ERROR);
	if (tp.so_path == NULL)
		exit_error(PATH_INIT_ERROR);
	if (tp.we_path == NULL)
		exit_error(PATH_INIT_ERROR);
	if (tp.ea_path == NULL)
		exit_error(PATH_INIT_ERROR);
}

bool	is_first_input(t_rgb color)
{
	if (color.red == -1 && color.green == -1 && color.blue == -1)
		return (true);
	return (false);
}

void	is_initialized_rgb(t_rgb color)
{
	if (color.red == -1)
		exit_error(RGB_INIT_ERROR);
	if (color.green == -1)
		exit_error(RGB_INIT_ERROR);
	if (color.blue == -1)
		exit_error(RGB_INIT_ERROR);
}

void	is_initialized_map(char **map)
{
	if (map == NULL)
		exit_error(MAP_INIT_ERROR);
}
