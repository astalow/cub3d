#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game_data	gd;

	check_arg(ac, av);
	init_game_data(&gd);
	read_cubfile(&gd, av[1]);
	set_game_data(&gd);
	free_cubfile(&gd);
	check_game_data(&gd);
	set_map_data(&gd);
	init_param(&gd);
	init_mlx(&gd);
	open_all_tex(&gd, &gd.imgs);
	loop_start(&gd);
	return (0);
}
