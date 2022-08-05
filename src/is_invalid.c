#include "cub3d.h"

void	is_invalid_rgb(t_rgb color)
{
	if (!(0 <= color.red && color.red <= 255))
		exit_error(RGB_INVALID_ERROR);
	if (!(0 <= color.green && color.green <= 255))
		exit_error(RGB_INVALID_ERROR);
	if (!(0 <= color.blue && color.blue <= 255))
		exit_error(RGB_INVALID_ERROR);
}
