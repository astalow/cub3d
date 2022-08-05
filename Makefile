NAME = cub3D
UNAME	=	$(shell uname)

SRC	=	map.c \
		collision.c \
		rays_utils1.c \
		rays_utils2.c \
		line_utils.c \
		line.c \
		init.c \
		is_open.c \
		color.c \
		coord.c \
		rays.c \
		free.c \
		key_hook.c \
		set_color.c \
		main.c \
		projection.c \
		loop.c \
		dupmap.c \
		check_game_data.c \
		set_texture_path.c \
		set_game_data.c \
		init_game_data.c \
		render.c \
		read_cubfile.c \
		circle.c \
		free_cubfile.c \
		is_initialized.c \
		is_invalid.c \
		check_arg.c \
		move.c \
		open_tex.c \
		check_N.c

SRCS =	$(addprefix ./src/, $(SRC))
SRCSB = $(addprefix ./src/, $(SRC))
SRCS += ./src/check_wall.c
SRCSB += ./src/check_wall_bonus.c

OBJS	= $(SRCS:%.c=%.o)
OBJSB	= $(SRCSB:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./libft
LIBFT = ft
MLXDIR	=	./minilibx-linux
MLX = mlx
INCLUDE = -I./include -I$(LIBFTDIR) -I$(MLXDIR)

LFLAG = -L$(LIBFTDIR) -l$(LIBFT) -L$(MLXDIR) -l$(MLX)
ifeq ($(UNAME),Darwin)
	LFLAG += -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
else
	LFLAG += -lXext -lX11 -lm
endif

ifdef WITH_BONUS
OBJS = $(OBJSB)
endif

.c.o :
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(MLXDIR)
	make bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LFLAG) -o $(NAME)

all : $(NAME)

clean :
	make clean -C ./libft
	make clean -C $(MLXDIR)
	rm -rf $(OBJS) $(OBJSB)

fclean : clean
	make fclean -C ./libft
	make clean -C $(MLXDIR)
	rm -rf $(NAME)
	rm -rf $(OBJS) $(OBJSB)

re : fclean all

bonus :
	make WITH_BONUS=1

.PHONY: all clean fclean re .c.o bonus
