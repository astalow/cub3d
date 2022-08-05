#include "cub3d.h"

static void	open_tex(t_game_data *data, t_img_data *img, char *path)
{
	img->ptr = \
		mlx_xpm_file_to_image(data->mlx, path, &img->width, &img->height);
	if (!img->ptr || img->width != TILE_SIZE || img->height != TILE_SIZE)
		free_exit(data, "Failed to load image");
	img->addr = (int *)mlx_get_data_addr(img->ptr, &img->bits_per_pixel, \
		&img->line_lenght, &img->endian);
	if (!img->addr)
		free_exit(data, INIT_ERROR);
}

void	open_all_tex(t_game_data *data, t_imgs *img)
{
	open_tex(data, &img->wall_north, data->tp.no_path);
	open_tex(data, &img->wall_south, data->tp.so_path);
	open_tex(data, &img->wall_east, data->tp.ea_path);
	open_tex(data, &img->wall_west, data->tp.we_path);
	open_tex(data, &img->door, DOOR_TEX_PATH);
}
