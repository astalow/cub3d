#include "cub3d.h"

static int	count_line(char *file_name)
{
	char	*line;
	int		fd;
	int		line_size;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error("The file could not be opened");
	line_size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		line_size++;
	}
	close(fd);
	return (line_size);
}

static char	**malloc_cubfile(t_game_data *gd, char *cubfile_name)
{
	char	**cubfile;

	gd->cubfile_linage = count_line(cubfile_name);
	cubfile = (char **)x_malloc((gd->cubfile_linage + 1) * sizeof(char *));
	return (cubfile);
}

void	read_cubfile(t_game_data *gd, char *cubfile_name)
{
	int		fd;
	int		i;
	char	*line;
	char	*new_line;

	gd->cubfile = malloc_cubfile(gd, cubfile_name);
	fd = open(cubfile_name, O_RDONLY);
	if (fd == -1)
		exit_error(CUB_OPEN_ERROR);
	i = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new_line = ft_strtrim(line, "\n");
		free(line);
		if (new_line == NULL)
			exit_error("ft_strtrim");
		gd->cubfile[i] = new_line;
		i++;
	}
	gd->cubfile[i] = NULL;
	close(fd);
}
