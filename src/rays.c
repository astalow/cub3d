#include "cub3d.h"

t_coord	get_intercept(t_player_data *p, double angle, t_direction d, int hv)
{
	t_coord	intercept;

	if (hv == HORIZONTAL)
	{
		intercept.y = floor(p->pos.y / TILE_SIZE) * TILE_SIZE;
		if (d.down == 1)
			intercept.y += TILE_SIZE;
		intercept.x = p->pos.x + (intercept.y - p->pos.y) / tan(angle);
	}
	else
	{
		intercept.x = floor(p->pos.x / TILE_SIZE) * TILE_SIZE;
		if (d.right == true)
			intercept.x += TILE_SIZE;
		intercept.y = p->pos.y + (intercept.x - p->pos.x) * tan(angle);
	}
	return (intercept);
}

t_coord	get_step(double angle, t_direction d, int hv)
{
	t_coord	step;

	if (hv == HORIZONTAL)
	{
		step.x = TILE_SIZE / tan(angle);
		step.y = TILE_SIZE;
		if (d.up == 1)
			step.y *= -1;
		if ((d.left == 1 && step.x > 0) || (d.right == 1 && step.x < 0))
			step.x *= -1;
	}
	else
	{
		step.x = TILE_SIZE;
		step.y = TILE_SIZE * tan(angle);
		if (d.left == true)
			step.x *= -1;
		if ((d.up == 1 && step.y > 0) || (d.down == 1 && step.y < 0))
			step.y *= -1;
	}
	return (step);
}

void	get_distance(t_game_data *data, t_fov *fov, t_ray *ray, int hv)
{
	t_coord	intercept;
	t_coord	step;
	t_coord	n;
	t_cell	*c;
	bool	first_door;

	init_neighbor(&n, fov->d, hv);
	first_door = false;
	step = get_step(fov->angle, fov->d, hv);
	intercept = get_intercept(&data->player, fov->angle, fov->d, hv);
	while (is_inside_map(data, intercept, n))
	{
		c = get_cell_addr(data, data->map2, add_coord(intercept, n));
		if (c->type == MAP_WALL)
			return (ret_on_collision(data, ray, intercept, false));
		if (c->type == MAP_DOOR)
		{
			if (first_door == false)
				store_nearest_door(&first_door, ray, add_coord(intercept, n));
			if (c->door_open == CLOSE)
				return (ret_on_collision(data, ray, intercept, true));
		}
		intercept = add_coord(intercept, step);
	}
	ray->distance = DBL_MAX;
}

void	calc_one_ray(t_game_data *data, t_fov *fov)
{
	t_ray	h;
	t_ray	v;

	ft_memset(&h, 0, sizeof(t_ray));
	ft_memset(&v, 0, sizeof(t_ray));
	fov->d = get_direction_of_line(fov->angle);
	get_distance(data, fov, &h, HORIZONTAL);
	get_distance(data, fov, &v, VERTICAL);
	if (h.distance >= v.distance)
		copy_to_fov(data, fov, &v, true);
	else
		copy_to_fov(data, fov, &h, false);
}

void	cast_all_rays(t_game_data *data)
{
	double	ray_angle;
	size_t	i;

	ray_angle = data->player.rotation_angle - (FOV / 2);
	i = 0;
	data->touching_door = NULL;
	while (i < (size_t)data->ray)
	{
		data->fov[i].id = i;
		data->fov[i].angle = normalize_angle(ray_angle);
		calc_one_ray(data, &data->fov[i]);
		ray_angle += (FOV / data->ray);
		i++;
	}
}
