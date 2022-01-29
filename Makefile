NAME = so_long

SRC = main.c \
$(addprefix src/, ft_game_loop.c ft_get_map.c ft_check_file_extension.c ft_build_images.c \
ft_get_info_from_map.c ft_key_hook.c ft_exit_hook.c ft_render.c ft_free.c \
ft_set_configs.c ft_exit_error.c)

LIBFTPATH = ./libft

CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Werror -Wall -Wextra -I

MINILIBX = -lmlx -lXext -lX11

.PHONY: all clean fclean re

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTPATH)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -L$(LIBFT) -lft $(MINILIBX) -o $(NAME)

clean:
	make -C ${LIBFTPATH} clean
	rm -rf *.o

fclean: clean
	make -C ${LIBFTPATH} fclean
	rm -f $(NAME)

re: fclean ${NAME}

test:
	./so_long ./maps/simple.ber

leak:
	leaks -atExit -- ./so_long ./maps/simple.ber
