#include "cub3d.h"

void	put_color(t_game_data *data, int x, int y)
{
	char	tile;

	tile = get_minimap_tile(data, x, y);
	if (tile == '1')
		data->map_img_data.addr[y * data->win_width + x] = 0x000000;
	else if (tile == '0'
		|| tile == 'N' || tile == 'E' || tile == 'W' || tile == 'S')
		data->map_img_data.addr[y * data->win_width + x] = 0xFFFFFF;
	else if (tile == MAP_DOOR)
		data->map_img_data.addr[y * data->win_width + x] = MINIMAP_DOOR_COLOR;
}

void	put_all_tile(t_game_data *data)
{
	int		x;
	int		y;
	int		row;
	int		col;

	row = (int)floor((TILE_SIZE * MINIMAP_SCALE) * data->rows);
	col = (int)floor((TILE_SIZE * MINIMAP_SCALE) * data->cols);
	y = 0;
	if ((size_t)row > data->win_height || (size_t)col > data->win_width)
		free_exit(data, MAPSIZE_ERROR);
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			put_color(data, x, y);
			x++;
		}
		y++;
	}
}
