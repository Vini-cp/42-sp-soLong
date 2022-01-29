NAME = so_long

SRC = $(addprefix src/, main.c ft_get_map.c ft_check_file_extension.c ft_build_images.c \
ft_get_info_from_map.c ft_key_hook.c ft_exit_hook.c ft_render.c ft_free.c \
ft_set_configs.c ft_exit_error.c ft_game_loop.c) 

LIBFTPATH = ./libft

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -g3 -Werror -Wall -Wextra

MINILIBX = -lmlx -lXext -lX11

.PHONY: all clean fclean re

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTPATH)
	$(CC) $(CFLAGS) -I$(LIBFTPATH) $(OBJ) -L$(LIBFTPATH) -lft $(MINILIBX) -o $(NAME)

clean:
	make -C ${LIBFTPATH} clean
	rm -rf $(OBJ)

fclean: clean
	make -C ${LIBFTPATH} fclean
	rm -rf $(NAME)

re: fclean ${NAME}

test:
	./so_long ./maps/simple.ber

leak:
	leaks -atExit -- ./so_long ./maps/simple.ber
