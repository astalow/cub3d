#include "cub3d.h"

int	close_window(void *data)
{
	t_game_data	*gd;

	gd = data;
	free_all(gd);
	exit(EXIT_SUCCESS);
}

int	mouse_hook(int button, int x, int y, void *data)
{
	t_game_data	*gd;
	size_t		ray_index;

	(void)y;
	if (button != MOUSE_LEFT)
		return (0);
	gd = data;
	ray_index = x * gd->ray / gd->win_width;
	if (ray_index > gd->ray)
		return (0);
	gd->player.rotation_angle = gd->fov[ray_index].angle;
	return (0);
}

int	loop_hook(t_game_data *data)
{
	render_all(data);
	mlx_put_image_to_window(data->mlx, data->win, data->map_img_data.ptr, 0, 0);
	return (0);
}

void	loop_start(t_game_data *data)
{
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, loop_hook, data);
	mlx_loop(data->mlx);
}
