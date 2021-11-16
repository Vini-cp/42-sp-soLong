#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "printf/include/printf.h"

# define WINDOW_NAME "soLong game"
# define TILE_WIDTH 32
# define SUCCESS_EXIT 1
# define FAILURE_EXIT 0

typedef struct win_render {
	void	*mlx;
	void	*win;
}	t_win_render;

int ft_start(void);
int	ft_get_map(int argc, char *argv[]);
int	ft_check_file_extension(char *file_name);

#endif
