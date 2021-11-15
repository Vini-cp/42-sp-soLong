CC = gcc

NAME = so_long.a

CFLAGS = -Werror -Wall -Wextra

MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

SRC = main.c


all: $(NAME)
.PHONY: all

${NAME}: fclean
	@${CC} ${CFLAGS} ${MINILIBX} ${SRC} -o ${NAME}
.PHONY: ${NAME}

clean:
	rm -rf *.o
.PHONY: clean

fclean: clean
.PHONY: fclean

re: fclean ${NAME}
.PHONY: re
