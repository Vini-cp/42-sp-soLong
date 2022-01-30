/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:11:25 by vcordeir          #+#    #+#             */
/*   Updated: 2022/01/30 03:08:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# define BUFFER_SIZE 32

typedef struct s_flags
{
	char			*f;
	char			*str;
	char			*spaces;
	char			print_c;
	int				s_len;
	int				just;
	int				prec;
	int				width;
	int				zero;
	int				neg;
	char			c;
}					t_flags;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void				*ft_calloc(size_t nelem, size_t elsize);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
int					ft_abs(int a);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isnegative(int num);
int					ft_isspace(int c);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
int					ft_memdel(void **ptr);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_strrev(char *str);
int					get_next_line(int fd, char **line);
/* printf files */
char				*ft_utoa(size_t num, int base, int capitalize);
char				*ft_ptoa(uintptr_t num, int prec);
char				*ft_ctoa(char c);
void				to_string(const char *f, va_list args, t_flags ***lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
int         ft_lstpop_back(t_list **lst);
int         ft_lstpop_front(t_list **lst);
void				ft_lstclear(t_list **lst);
void				ft_lstdelone(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(int));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);

#endif
