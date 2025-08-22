CC = cc
SRCS = cube.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		colision.c \
		initialize.c \
		ft_malloc.c \
		cast_rays.c


FLAGS = -Wall -Wextra -Werror 
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
