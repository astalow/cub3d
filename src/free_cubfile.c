#include "cub3d.h"

void	free_cubfile(t_game_data *gd)
{
	int	i;

	i = 0;
	while (gd->cubfile[i] != NULL)
	{
		free(gd->cubfile[i]);
		i++;
	}
	free(gd->cubfile);
}
