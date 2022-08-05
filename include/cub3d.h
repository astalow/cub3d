#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include <float.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include "mlx.h"

# define TITLE "cub3D"

# define KEY_ESC 0xff1b
# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_SPACE 32
# define MOUSE_LEFT 1

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768

# define MAP_WALL '1'
# define MAP_DOOR 'D'

# define OPEN 1
# define CLOSE 0

# define TILE_SIZE 64
# define MINIMAP_SCALE 0.2

# define PLAYER_CIRCLE_COLOR 0x52ff00
# define MINIMAP_RAY_COLOR 0xffff00
# define MINIMAP_DOOR_COLOR 0x696969

# define FOV 1.0471975512
# define WALL_STRIP_WIDTH 1

# define T_PREFIX_SIZE 3
# define C_PREFIX_SIZE 2

# define DOOR_TEX_PATH "./texture/door.xpm"

typedef enum e_part
{
	WALL,
	CEILING,
	FLOOR
}	t_part;

typedef enum e_hv
{
	HORIZONTAL,
	VERTICAL
}	t_hv;

typedef enum e_move
{
	FRONT,
	BACK,
	RIGHT,
	LEFT
}	t_move;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_cell
{
	char	type;
	bool	door_open;
}	t_cell;

typedef struct s_ray
{
	t_coord	hit;
	double	distance;
	bool	is_hit_door;
	t_coord	touching_door;
}	t_ray;

typedef struct s_texture_path
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_texture_path;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
	int	code;
}	t_rgb;

typedef struct s_direction{
	bool	up;
	bool	left;
	bool	down;
	bool	right;
}	t_direction;

typedef struct s_fov{
	int			id;
	double		angle;
	t_direction	d;
	double		distance;
	t_coord		wall_hit;
	bool		was_hit_vert;
	double		wall_strip_height;
	bool		is_door;
}	t_fov;

typedef struct s_img_data
{
	void	*ptr;
	int		*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		width;
	int		height;
}	t_img_data;

typedef struct s_imgs
{
	t_img_data	wall_north;
	t_img_data	wall_south;
	t_img_data	wall_east;
	t_img_data	wall_west;
	t_img_data	door;
}	t_imgs;

typedef struct s_player_data
{
	t_coord	pos;
	int		radius;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
}	t_player_data;

typedef struct s_game_data
{
	t_texture_path	tp;
	t_rgb			floor_color;
	t_rgb			ceiling_color;
	int				cubfile_linage;
	char			**cubfile;
	char			**map;
	t_cell			**map2;
	void			*mlx;
	void			*win;
	t_player_data	player;
	t_img_data		map_img_data;
	t_fov			*fov;
	t_imgs			imgs;
	size_t			ray;
	size_t			map_width;
	size_t			map_height;
	size_t			win_width;
	size_t			win_height;
	size_t			rows;
	size_t			cols;
	bool			is_touching_door;
	t_cell			*touching_door;
}	t_game_data;

typedef struct s_can_read_color
{
	bool	floor;
	bool	ceiling;
}	t_can_read_color;

typedef struct s_can_read_texture
{
	bool	north;
	bool	south;
	bool	west;
	bool	east;
}	t_can_read_texture;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

// 3d.c
void		render_projection_wall(t_game_data *data, t_fov *fov);

// check_arg.c
void		check_arg(int ac, char **av);

// check_game_data.c
void		check_game_data(t_game_data *gd);

// check_wall.c
void		check_wall(t_game_data *gd);

// check_N.c
void		check_N(char **map);

// circle.c
void		draw_circle(t_game_data *data);

// collision.c
char		get_minimap_tile(t_game_data *data, double x, double y);

// color.c
t_rgb		get_rgb_from_code(int color);
int			darken_color(int color, double distance);

// coord.c
int			to_chr_index(int width, t_coord coord, double scale);
t_cell		*get_cell_addr(t_game_data *gd, t_cell **map, t_coord coord);
t_coord		floor_coord(t_coord coord);
t_position	divide_coord(t_coord coord, double denominator);

//dupmap.c
int			get_line_size(char **map);
char		**dupmap(char **map);

// free_cubfile.c
void		free_cubfile(t_game_data *gd);

// free.c
void		free_all(t_game_data *data);
void		free_exit(t_game_data *data, char *msg);
void		free_map(char **map);

// init_game_data.c
void		init_player_pos(t_game_data *gd);
void		init_game_data(t_game_data *gd);

// init.c
void		init_mlx(t_game_data *data);
void		set_map_data(t_game_data *gd);
void		init_param(t_game_data *data);

// open_tex.c
void		open_all_tex(t_game_data *data, t_imgs *img);

// is_initialized.c
void		is_initialized_texture_path(t_texture_path tp);
void		is_initialized_rgb(t_rgb color);
void		is_initialized_map(char **map);
bool		is_first_input(t_rgb color);

// is_invalid.c
void		is_invalid_rgb(t_rgb color);

// is_open.c
void		is_open_texture_path(t_texture_path tp);

// key_hook.c
int			key_hook(int keycode, t_game_data *data);

// line_utils.c
void		get_delta(double *delta_x, double *delta_y);
bool		is_inside_blank(t_game_data *data, size_t index);
int			*get_tex(t_game_data *data, t_fov *fov);
int			get_index(t_game_data *data, t_fov *fov, int y);
int			get_tex_color(t_game_data *data, t_fov *fov, int y);

// line.c
void		draw_straight_line(t_game_data *data,
				t_coord start, double length, t_part p);
void		draw_wall_line(t_game_data *data, t_fov *fov,
				t_coord start, double length);
void		draw_line(t_game_data *data, t_coord start,
				t_coord goal, int color);

//loop.c
void		loop_start(t_game_data *data);
int			close_window(void *data);

// map.c
void		put_all_tile(t_game_data *data);

// rays_utils1.c
double		normalize_angle(double angle);
double		distance_between_points(t_coord start, t_coord goal);
t_direction	get_direction_of_line(double angle);
t_coord		add_coord(t_coord c1, t_coord c2);

// rays_utils2.c
void		ret_on_collision(t_game_data *data, t_ray *ray,
				t_coord intercept, bool door);
void		init_neighbor(t_coord *n, t_direction d, t_hv hv);
void		store_nearest_door(bool	*flag, t_ray *ray, t_coord coord);
bool		is_inside_map(t_game_data *gd, t_coord intercept, t_coord n);
void		copy_to_fov(t_game_data *data, t_fov *fov, t_ray *ray, bool hv);

// ray.c
void		cast_all_rays(t_game_data *data);

// read_cubfile.c
void		read_cubfile(t_game_data *gd, char *cubfile_name);

// render.c
void		render_all(t_game_data *data);

// set_color.c
t_rgb		get_color(char *line);

// set_game_data.c
char		*get_texture_path(char *line);
void		set_game_data(t_game_data *gd);

// move.c
bool		is_reachable(t_game_data *gd, t_cell **map, t_coord coord);

#endif
