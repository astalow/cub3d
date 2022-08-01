/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisoya <tisoya@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:04:49 by tkirihar          #+#    #+#             */
/*   Updated: 2022/08/01 15:27:01 by tisoya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_start_line(char *line)
{
	int	i;

	if (line[0] == '\0')
		return (false);
	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_strchr(" 1", line[i]))
			return (false);
		i++;
	}
	return (true);
}

int	get_map_start(char **file)
{
	int	i;

	i = 0;
	while (file[i] != NULL)
	{
		if (is_map_start_line(file[i]))
			return (i);
		i++;
	}
	exit_error(CUB_FORMAT_ERROR);
	return (0);
}

char	**malloc_map(t_game_data *gd, int map_start)
{
	char	**map;

	map = (char **)ft_calloc((gd->cubfile_linage - map_start + 1)
			* sizeof(char *), 1);
	return (map);
}

void	set_texture_and_color(t_game_data *gd, int i)
{
	char	*prefix;

	prefix = ft_substr(gd->cubfile[i], 0, PREFIX_SIZE);
	if (!ft_strncmp(prefix, "NO", 2) && gd->tp.no_path == NULL)
		gd->tp.no_path = get_texture_path(gd->cubfile[i]);
	else if (!ft_strncmp(prefix, "SO", 2) && gd->tp.so_path == NULL)
		gd->tp.so_path = get_texture_path(gd->cubfile[i]);
	else if (!ft_strncmp(prefix, "WE", 2) && gd->tp.we_path == NULL)
		gd->tp.we_path = get_texture_path(gd->cubfile[i]);
	else if (!ft_strncmp(prefix, "EA", 2) && gd->tp.ea_path == NULL)
		gd->tp.ea_path = get_texture_path(gd->cubfile[i]);
	else if (!ft_strncmp(prefix, "F ", 2))
		gd->floor_color = get_color(gd->cubfile[i]);
	else if (!ft_strncmp(prefix, "C ", 2))
		gd->ceiling_color = get_color(gd->cubfile[i]);
	else if (gd->cubfile[i][0] != '\0')
		exit_error(CUB_FORMAT_ERROR);
	free(prefix);
}

void	set_game_data(t_game_data *gd)
{
	int		i;
	int		map_start;

	i = 0;
	map_start = get_map_start(gd->cubfile);
	gd->map = malloc_map(gd, map_start);
	while (gd->cubfile[i] != NULL)
	{
		if (i < map_start)
			set_texture_and_color(gd, i);
		else
		{
			if (gd->cubfile[i][0] == '\0')
				exit_error(MAP_INVALID_ERROR);
			gd->map[i - map_start] = ft_strdup(gd->cubfile[i]);
		}
		i++;
	}
	gd->map[i - map_start] = NULL;
}
