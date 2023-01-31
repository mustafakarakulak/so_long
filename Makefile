NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -L./mlx -lmlx -I./printf -framework AppKit -framework OpenGL
SRCS =  so_long.c \
		lib/ft_split.c lib/ft_itoa.c lib/ft_strdup.c\
		mapcheck/ft_mapread.c mapcheck/ft_general_control.c lib/ft_calloc.c \
		lib/ft_bzero.c lib/ft_memset.c  mapcheck/ft_window.c ft_move.c mapcheck/ft_playable_control.c \
		mapcheck/ft_wall_control.c mapcheck/ft_control_map_check.c lib/ft_printf.c lib/ft_source.c ft_utils.c \
		ft_utils1.c mapcheck/ft_mouse_window.c


Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

OBJS= $(SRCS:.c=.o)
MINI = ./mlx/libmlx.a
RED = '\033[0;31m'

all: ${NAME}

$(PRNTF): 
	@make -C ./printf

$(MINI):
	@make -C ./mlx

$(NAME): $(MINI) $(OBJS) 
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME)
	@echo "\033[1;96mStarted Program\033[1;96m"

%.o: %.c
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra -g

clean:
	@rm -rf ${OBJS}
	@echo $(R)Removed [$(OBJS)]$(B)
	@make clean -C mlx/

fclean: clean
	@rm -rf ${NAME}
	@echo $(R)Removed [$(NAME)]$(B)
	@make clean -C mlx/

re: fclean all
.PHONY: fclean re all clean