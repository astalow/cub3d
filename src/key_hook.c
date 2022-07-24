#include "cub3d.h"

void	turn_player(t_game_data *data, t_move m)
{
	int	direction;

	direction = 1;
	if (m == LEFT)
		direction = -1;
	data->player.rotation_angle += data->player.rotation_speed * direction;
}

void	move_player(t_game_data *data, t_move m)
{
	double			move_step;
	double			new_x;
	double			new_y;
	t_player_data	*p;

	p = &data->player;
	move_step = p->move_speed;
	if (m == BACK || m == LEFT)
		move_step *= -1;
	if (m == FRONT || m == BACK)
	{
		new_x = p->pos.x + cos(p->rotation_angle) * move_step;
		new_y = p->pos.y + sin(p->rotation_angle) * move_step;
	}
	else
	{
		new_x = p->pos.x + cos(p->rotation_angle + M_PI / 2) * move_step;
		new_y = p->pos.y + sin(p->rotation_angle + M_PI / 2) * move_step;
	}
	if (!has_wall(data, new_x, new_y))
	{
		p->pos.x = new_x;
		p->pos.y = new_y;
	}
}

int	key_hook(int keycode, t_game_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W)
		move_player(data, FRONT);
	else if (keycode == KEY_A)
		move_player(data, LEFT);
	else if (keycode == KEY_S)
		move_player(data, BACK);
	else if (keycode == KEY_D)
		move_player(data, RIGHT);
	else if (keycode == KEY_RIGHT)
		turn_player(data, RIGHT);
	else if (keycode == KEY_LEFT)
		turn_player(data, LEFT);
	return (0);
}
