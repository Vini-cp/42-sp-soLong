NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_substr.c ft_abs.c \
ft_tolower.c ft_toupper.c ft_strjoin.c ft_calloc.c ft_strlcpy.c ft_strlcat.c \
ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strmapi.c ft_strnstr.c ft_strdup.c \
ft_memcmp.c ft_memccpy.c  ft_split.c ft_strtrim.c ft_isnegative.c ft_itoa.c\
ft_isspace.c ft_max.c ft_min.c ft_memdel.c ft_strrev.c \
ft_printf_putchar.c ft_printf_print.c ft_printf_print_p_str.c \
ft_printf_print_c.c ft_printf_isflag.c ft_printf_empty_zeros.c ft_ptoa.c \
ft_printf_get_flag.c ft_printf_newflag.c to_string.c ft_ctoa.c ft_printf.c \
ft_utoa.c \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstiter.c ft_lstnew.c \
ft_lstsize.c ft_lstlast.c ft_lstpop_front.c ft_lstpop_back.c

FOLDER = src

SRCS = $(addprefix ${FOLDER}/, ${SRC})

OBJ = $(SRCS:.c=.o)

RUNFLAGS = -Wall -Werror -Wextra

CFLAGS += -Wall -Werror -Wextra -I./ -c

.PHONY: all clean fclean re

all:    $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJ)
	rm *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

test:
	gcc $(RUNFLAGS) $(TEST) ./$(NAME) \
	&& ./a.out \
	&& rm ./a.out
