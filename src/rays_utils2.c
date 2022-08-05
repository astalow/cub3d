#include "cub3d.h"

void
	ret_on_collision(t_game_data *data, t_ray *ray,
	t_coord intercept, bool door)
{
	ray->hit = intercept;
	ray->distance = distance_between_points(data->player.pos, ray->hit);
	ray->is_hit_door = door;
}

void	init_neighbor(t_coord *n, t_direction d, t_hv hv)
{
	ft_memset(n, 0, sizeof(t_coord));
	if (hv == HORIZONTAL && d.up == true)
		n->y = -1;
	else if (hv == VERTICAL && d.left == true)
		n->x = -1;
}

void	store_nearest_door(bool	*flag, t_ray *ray, t_coord coord)
{
	ray->touching_door = coord;
	*flag = true;
}

bool	is_inside_map(t_game_data *gd, t_coord intercept, t_coord n)
{
	t_coord	c;

	if (!(intercept.x >= 0 && intercept.x < gd->map_width
			&& intercept.y >= 0 && intercept.y < gd->map_height))
		return (false);
	c = add_coord(intercept, n);
	if (!(c.x >= 0 && c.x < gd->map_width
			&& c.y >= 0 && c.y < gd->map_height))
		return (false);
	return (true);
}

void	copy_to_fov(t_game_data *data, t_fov *fov, t_ray *ray, bool hv)
{
	fov->distance = ray->distance;
	fov->wall_hit = ray->hit;
	fov->was_hit_vert = hv;
	fov->is_door = ray->is_hit_door;
	if ((size_t)fov->id == data->ray / 2)
	{
		data->touching_door
			= get_cell_addr(data, data->map2, ray->touching_door);
		if (distance_between_points(data->player.pos,
				ray->touching_door) < TILE_SIZE)
			data->is_touching_door = true;
		else
			data->is_touching_door = false;
	}
}
