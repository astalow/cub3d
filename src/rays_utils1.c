#include "cub3d.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

double	distance_between_points(t_coord start, t_coord goal)
{
	double	x;
	double	y;

	x = goal.x - start.x;
	y = goal.y - start.y;
	return (sqrt(x * x + y * y));
}

t_direction	get_direction_of_line(double angle)
{
	t_direction	d;

	ft_memset(&d, false, sizeof(t_direction));
	if (angle > 0 && angle < M_PI)
		d.down = true;
	else
		d.up = true;
	if (angle < 0.5 * M_PI || angle > 1.5 * M_PI)
		d.right = true;
	else
		d.left = true;
	return (d);
}

t_coord	add_coord(t_coord c1, t_coord c2)
{
	t_coord	ret;

	ret.x = c1.x + c2.x;
	ret.y = c1.y + c2.y;
	return (ret);
}
