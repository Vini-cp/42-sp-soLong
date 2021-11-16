CC = gcc

NAME = so_long.a

PRINTFNAME = libftprintf.a

PRINTFPATH = ./printf

CFLAGS = -Werror -Wall -Wextra

MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

OBJS := $(*.o)

SRC = ./src/*.c


all: $(NAME)
.PHONY: all

${NAME}: fclean
	@make -C ${PRINTFPATH}
	@mv $(PRINTFPATH)/${PRINTFNAME} ${PRINTFNAME}
	@${CC} ${CFLAGS} ${SRC} ${PRINTFNAME} ${MINILIBX} main.c -o ${NAME}

clean:
	@rm -rf *.o
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(PRINTFNAME)
.PHONY: fclean

re: fclean ${NAME}
.PHONY: re
