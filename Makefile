NAME = so_long

SRC = ft_game_loop.c ft_get_map.c ft_check_file_extension.c ft_build_images.c \
ft_get_info_from_map.c ft_key_hook.c ft_exit_hook.c ft_render.c ft_free.c \
ft_set_configs.c ft_exit_error.c

FOLDER = src

SRCS = $(addprefix ${FOLDER}/, ${SRC})

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

LIBFTPATH = ./libft

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MAC_MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

LINUX_MINILIBX = ./mlx_linux/libmlx_Linux.a -I./mlx_linux/ -L./mlx_linux/ -lmlx -lXext -lX11

OBJS := $(*.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)/${LIBFT} ${LIBFT}
	${CC} ${CFLAGS} ${SRCS} ${OBJS} ${LIBFT} ${MAC_MINILIBX} main.c -o ${NAME}

clean:
	make -C ${LIBFTPATH} clean
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
