CC = cc
SRCS = cube.c
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
NAME = cube

%.o : %.c
	$(CC) $(FLAGS) -I/usr/local/include -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -L/usr/local/lib -lmlx_Linux -lXext -lX11 -lm -lz -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
