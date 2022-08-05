#include "cub3d.h"

void	init_texture_path(t_texture_path *tp)
{
	tp->no_path = NULL;
	tp->so_path = NULL;
	tp->we_path = NULL;
	tp->ea_path = NULL;
}

void	init_rgb(t_rgb *color)
{
	color->red = -1;
	color->green = -1;
	color->blue = -1;
}

void	init_game_data(t_game_data *gd)
{
	ft_bzero(gd, sizeof(t_game_data));
	init_texture_path(&(gd->tp));
	init_rgb(&(gd->ceiling_color));
	init_rgb(&(gd->floor_color));
	gd->map = NULL;
}

bool	get_player_param(const char *s, size_t *i, char *d)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	*i = 0;
	while (str[*i])
	{
		if (str[*i] == 'N' || str[*i] == 'S'
			|| str[*i] == 'W' || str[*i] == 'E')
		{
			*d = str[*i];
			return (true);
		}
		(*i)++;
	}
	return (false);
}

void	init_player_pos(t_game_data *gd)
{
	size_t	y;
	size_t	x;
	char	d;

	y = 0;
	x = 0;
	while (gd->map[y])
	{
		if (get_player_param(gd->map[y], &x, &d) == true)
			break ;
		y++;
	}
	gd->player.pos.x = x * TILE_SIZE + TILE_SIZE / 2;
	gd->player.pos.y = y * TILE_SIZE + TILE_SIZE / 2;
	if (d == 'N')
		gd->player.rotation_angle = M_PI * 3 / 2;
	else if (d == 'S')
		gd->player.rotation_angle = M_PI / 2;
	else if (d == 'E')
		gd->player.rotation_angle = 0;
	else if (d == 'W')
		gd->player.rotation_angle = M_PI;
}
