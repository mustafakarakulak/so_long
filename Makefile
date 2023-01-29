CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
NAME = so_long
SRC = so_long.c so_long_utils.c map_check.c libft_utils.c
OBJ = $(SRC:.c=.o)
MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all