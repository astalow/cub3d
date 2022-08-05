#include "cub3d.h"

static bool	is_wall(t_game_data *gd, t_cell **map, t_position p)
{
	t_cell	m;

	if (p.x < 0 || p.y < 0 || \
	(size_t)p.y >= gd->rows || (size_t)p.x >= gd->cols)
		return (true);
	m = map[p.y][p.x];
	return (m.type == MAP_WALL || (m.type == MAP_DOOR && m.door_open == CLOSE));
}

static void	set_diagonal_cell(t_position new, t_position player, \
		t_position *p, t_position *p2)
{
	if (new.x > player.x && new.y > player.y)
	{
		(*p).x = player.x + 1;
		(*p2).y = player.y + 1;
	}
	else if (new.x > player.x && new.y < player.y)
	{
		(*p).x = player.x + 1;
		(*p2).y = player.y - 1;
	}
	else if (new.x < player.x && new.y < player.y)
	{
		(*p).x = player.x - 1;
		(*p2).y = player.y - 1;
	}
	else if (new.x < player.x && new.y > player.y)
	{
		(*p).x = player.x - 1;
		(*p2).y = player.y + 1;
	}
}

bool	is_reachable_diagonal(t_game_data *gd, t_cell **map, \
		t_position new, t_position player)
{
	t_position	p;
	t_position	p2;

	p = player;
	p2 = player;
	if (new.x < 0 || new.y < 0 || \
	(size_t)new.x >= gd->cols || (size_t)new.y >= gd->rows)
		return (false);
	set_diagonal_cell(new, player, &p, &p2);
	if (is_wall(gd, map, p) == true && is_wall(gd, map, p2) == true)
		return (false);
	return (true);
}

bool	is_reachable(t_game_data *gd, t_cell **map, t_coord coord)
{
	t_position	player;
	t_position	new;

	player = divide_coord(gd->player.pos, TILE_SIZE);
	new = divide_coord(coord, TILE_SIZE);
	if (player.x == new.x && player.y == new.y)
		return (true);
	if ((size_t)new.x >= gd->cols || (size_t)new.y >= gd->rows)
		return (false);
	if (is_wall(gd, map, new))
		return (false);
	if (!is_reachable_diagonal(gd, map, new, player))
		return (false);
	return (true);
}
