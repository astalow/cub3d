#include "cub3d.h"

void	get_delta(double *delta_x, double *delta_y)
{
	double	step;

	if (fabs(*delta_x) > fabs(*delta_y))
		step = fabs(*delta_x);
	else
		step = fabs(*delta_y);
	*delta_x /= step;
	*delta_y /= step;
}

bool	is_inside_blank(t_game_data *data, size_t index)
{
	if (!(index <= (data->map_width * data->map_height)))
		return (false);
	if (data->map_img_data.addr[index] == 0x0)
		return (false);
	return (true);
}

int	*get_tex(t_game_data *data, t_fov *fov)
{
	if (fov->is_door == true)
		return (data->imgs.door.addr);
	else
	{
		if (fov->d.up == true && fov->was_hit_vert == false)
			return (data->imgs.wall_north.addr);
		else if (fov->d.right == true && fov->was_hit_vert == true)
			return (data->imgs.wall_east.addr);
		else if (fov->d.left == true && fov->was_hit_vert == true)
			return (data->imgs.wall_west.addr);
		else if (fov->d.down == true && fov->was_hit_vert == false)
			return (data->imgs.wall_south.addr);
	}
	return (data->imgs.wall_north.addr);
}

int	get_index(t_game_data *data, t_fov *fov, int y)
{
	int		tex_offset_x;
	int		tex_offset_y;
	size_t	wall_bottom_pixel;

	wall_bottom_pixel = (data->win_height / 2) + (fov->wall_strip_height / 2);
	if (wall_bottom_pixel > data->win_height)
		wall_bottom_pixel = data->win_height;
	if (fov->was_hit_vert == true)
		tex_offset_x = (int)floor(fov->wall_hit.y) % TILE_SIZE;
	else
		tex_offset_x = (int)floor(fov->wall_hit.x) % TILE_SIZE;
	tex_offset_y = y * ((double)(TILE_SIZE) / fov->wall_strip_height);
	if ((fov->d.up == true && fov->was_hit_vert == false)
		|| (fov->d.right == true && fov->was_hit_vert == true))
		return (tex_offset_y * TILE_SIZE + tex_offset_x);
	else if ((fov->d.left == true && fov->was_hit_vert == true)
		|| (fov->d.down == true && fov->was_hit_vert == false))
		return (tex_offset_y * TILE_SIZE + (TILE_SIZE - 1 - tex_offset_x));
	return (0);
}

int	get_tex_color(t_game_data *data, t_fov *fov, int y)
{
	int		color;
	int		*tex;
	int		index;

	tex = get_tex(data, fov);
	index = get_index(data, fov, y);
	color = darken_color(tex[index], fov->distance);
	return (color);
}
