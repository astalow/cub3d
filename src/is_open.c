#include "cub3d.h"

static void	is_open_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error(PATH_OPEN_ERROR);
	close(fd);
}

void	is_open_texture_path(t_texture_path tp)
{
	is_open_path(tp.no_path);
	is_open_path(tp.so_path);
	is_open_path(tp.we_path);
	is_open_path(tp.ea_path);
}
