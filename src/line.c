#include "cub3d.h"

void	draw_line(t_game_data *data, t_coord start, t_coord goal, int color)
{
	double		delta_x;
	double		delta_y;
	size_t		index;
	t_img_data	*m;

	m = &data->map_img_data;
	start = floor_coord(start);
	goal = floor_coord(goal);
	delta_x = goal.x - start.x;
	delta_y = goal.y - start.y;
	get_delta(&delta_x, &delta_y);
	while (fabs(goal.x - start.x) > 0.01 || fabs(goal.y - start.y) > 0.01)
	{
		index = to_chr_index(data->win_width, start, 1);
		if (is_inside_blank(data, index))
			m->addr[index] = color;
		start.x += delta_x;
		start.y += delta_y;
	}
	index = to_chr_index(data->win_width, start, 1);
	if (is_inside_blank(data, index))
		m->addr[index] = color;
}

void	draw_straight_line(t_game_data *data,
		t_coord start, double length, t_part p)
{
	size_t		index;
	size_t		i;
	t_img_data	*m;
	int			c;

	if (p == CEILING)
		c = data->ceiling_color.code;
	else
		c = data->floor_color.code;
	m = &data->map_img_data;
	i = 0;
	start = floor_coord(start);
	if (start.y < 0)
	{
		i = start.y * -1;
		start.y = 0;
	}
	while (i < length && start.y < data->win_height)
	{
		index = to_chr_index(data->win_width, start, 1);
		if (index < data->win_width * data->win_height)
			m->addr[index] = c;
		start.y++;
		i++;
	}
}

void	draw_wall_line(t_game_data *data, t_fov *fov,
		t_coord start, double length)
{
	size_t		index;
	size_t		i;
	t_img_data	*m;

	m = &data->map_img_data;
	i = 0;
	start = floor_coord(start);
	if (start.y < 0)
	{
		i = start.y * -1;
		start.y = 0;
	}
	while (i < length && start.y < data->win_height)
	{
		index = to_chr_index(data->win_width, start, 1);
		if (index < data->win_width * data->win_height)
			m->addr[index] = get_tex_color(data, fov, i);
		start.y++;
		i++;
	}
}
