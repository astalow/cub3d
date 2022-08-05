#include "cub3d.h"

bool	is_in_minimap(t_coord coord, int width, int height)
{
	return (!(coord.x * MINIMAP_SCALE > width * MINIMAP_SCALE
			|| coord.x < 0
			|| coord.y * MINIMAP_SCALE > height * MINIMAP_SCALE
			|| coord.y < 0));
}

bool	is_in_circle(t_coord center, t_coord coord, int radius)
{
	double	x;
	double	y;

	x = coord.x - center.x;
	y = coord.y - center.y;
	return (x * x + y * y <= radius * radius);
}

void	draw_circle(t_game_data *data)
{
	int		*ptr;
	t_coord	coord;

	ptr = data->map_img_data.addr;
	coord.x = floor(data->player.pos.x - data->player.radius);
	coord.y = floor(data->player.pos.y - data->player.radius);
	while (coord.y < floor(data->player.pos.y + data->player.radius))
	{
		coord.x = floor(data->player.pos.x - data->player.radius);
		while (coord.x < floor(data->player.pos.x + data->player.radius))
		{
			if (!is_in_minimap(coord, data->map_width, data->map_height))
				break ;
			if (is_in_circle(data->player.pos, coord, data->player.radius))
				ptr[to_chr_index(data->win_width, coord, MINIMAP_SCALE)]
					= PLAYER_CIRCLE_COLOR;
			coord.x++;
		}
		coord.y++;
	}
}
