CC = cc
SRCS = ray_casting/main.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		ray_casting/puting_image.c \
		ray_casting/WallDis.c \
		ray_casting/WallDis2.c \
		ray_casting/key_check.c \
		ray_casting/initialize.c \
		ray_casting/ft_malloc.c \
		ray_casting/texture_info.c \
		ray_casting/derection.c \
		ray_casting/ft_exit.c \
		parsing/check_characters.c \
		parsing/config.c \
		parsing/file_checker.c \
		parsing/map_checker.c \
		parsing/libft/ft_split.c \
		parsing/libft/helper_functions1.c \
		parsing/libft/helper_functions2.c \
		ray_casting/key_hook.c \
		parsing/file.c \
		parsing/read_map.c parsing/minimap.c

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
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
