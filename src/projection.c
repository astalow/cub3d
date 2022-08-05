#include "cub3d.h"

static double
	calc_flat_distance(double distance, double ray_angle, double player_angle)
{
	double	flat_distance;

	flat_distance = distance * cos(ray_angle - player_angle);
	if (flat_distance < 0.1)
		flat_distance = 0.1;
	return (flat_distance);
}

static void	set_param(t_coord *c, double *len, t_fov *fov, size_t win_height)
{
	c[0].x = fov->id * WALL_STRIP_WIDTH;
	c[0].y = 0;
	c[1].x = fov->id * WALL_STRIP_WIDTH;
	c[1].y = (win_height / 2) - (fov->wall_strip_height / 2) + 1;
	c[2].x = fov->id * WALL_STRIP_WIDTH;
	c[2].y = c[1].y + fov->wall_strip_height;
	len[0] = (win_height / 2) - (fov->wall_strip_height / 2);
	len[1] = fov->wall_strip_height;
	len[2] = win_height;
}

void	render_projection_wall(t_game_data *data, t_fov *fov)
{
	double	ray_distance;
	double	distance_projection_plane;
	t_coord	start[3];
	double	length[3];
	size_t	i;

	i = 0;
	distance_projection_plane = (data->win_width / 2) / tan(FOV / 2);
	while (i < data->ray)
	{
		ray_distance = calc_flat_distance(fov[i].distance, fov[i].angle, \
			data->player.rotation_angle);
		fov[i].wall_strip_height = (TILE_SIZE / ray_distance) \
		* distance_projection_plane;
		set_param(start, length, &fov[i], data->win_height);
		if (length[0] > 0)
			draw_straight_line(data, start[0], length[0], CEILING);
		draw_wall_line(data, &fov[i], start[1], length[1]);
		if (start[2].y < data->win_height)
			draw_straight_line(data, start[2], length[2], FLOOR);
		i++;
	}
}
