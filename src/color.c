#include "cub3d.h"

t_rgb	get_rgb_from_code(int color)
{
	t_rgb	rgb;

	rgb.red = color >> 16;
	rgb.green = color >> 8 & 0xFF;
	rgb.blue = color & 0xFF;
	return (rgb);
}

int	darken_color(int color, double distance)
{
	t_rgb	rgb;
	double	dark;

	rgb = get_rgb_from_code(color);
	dark = (200 / distance);
	if (dark > 1)
		return (color);
	rgb.red *= dark;
	rgb.green *= dark;
	rgb.blue *= dark;
	if (rgb.red > 0xFF)
		rgb.red = 0xFF;
	if (rgb.green > 0xFF)
		rgb.green = 0xFF;
	if (rgb.blue > 0xFF)
		rgb.blue = 0xFF;
	if (rgb.red < 0)
		rgb.red = 0;
	if (rgb.green < 0)
		rgb.green = 0;
	if (rgb.blue < 0)
		rgb.blue = 0;
	return (rgb.red << 16 | rgb.green << 8 | rgb.blue);
}
