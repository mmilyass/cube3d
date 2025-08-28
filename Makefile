CC = cc
SRCS = cube.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		ray_casting/cast_rays.c \
		ray_casting/puting_image.c \
		ray_casting/WallDis.c \
		ray_casting/WallDis2.c \
		colision.c \
		initialize.c \
		ft_malloc.c \
		key_check.c \
		rendering_2Dmap.c 


FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
OBJS = $(SRCS:.c=.o)
NAME = cube

%.o : %.c cube.h
	$(CC) $(FLAGS) -I/usr/local/include -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L/usr/local/lib -lmlx_Linux -lXext -lX11 -lm -lz -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
