#include "cub3d.h"

void	draw_minimap_ray(t_game_data *data)
{
	t_coord	start;
	t_coord	goal;
	size_t	i;

	i = 0;
	start.x = data->player.pos.x * MINIMAP_SCALE;
	start.y = data->player.pos.y * MINIMAP_SCALE;
	while (i < data->ray)
	{
		goal.x = data->fov[i].wall_hit.x * MINIMAP_SCALE;
		goal.y = data->fov[i].wall_hit.y * MINIMAP_SCALE;
		draw_line(data, start, goal, MINIMAP_RAY_COLOR);
		i++;
	}
}

void	render_all(t_game_data *data)
{
	cast_all_rays(data);
	render_projection_wall(data, data->fov);
	put_all_tile(data);
	draw_minimap_ray(data);
	draw_circle(data);
}
