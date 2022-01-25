NAME = so_long

SRC = main.c \
$(addprefix src/, ft_game_loop.c ft_get_map.c ft_check_file_extension.c ft_build_images.c \
ft_get_info_from_map.c ft_key_hook.c ft_exit_hook.c ft_render.c ft_free.c \
ft_set_configs.c ft_exit_error.c)

OBJ := $(SRC:%.c=%.o)

LIBFTPATH = ./libft

CC = gcc

CFLAGS = -Werror -Wall -Wextra -I ./ -g

LIBRARIES = -L ./minilibx -lmlx -lXext -lX11 -L ./libft -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./minilibx
	make -C ${LIBFTPATH}
	$(CC) $(CFLAGS) $(OBJ) $(LIBRARIES) -o $(NAME)

clean:
	make -C ${LIBFTPATH} clean
	make -C ./minilibx clean
	rm -rf *.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make -C ${LIBFTPATH} fclean

re: fclean ${NAME}

test:
	./so_long ./maps/simple.ber

leak:
	leaks -atExit -- ./so_long ./maps/simple.ber
