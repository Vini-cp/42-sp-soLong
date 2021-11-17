#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "printf/include/printf.h"

# define WINDOW_NAME "soLong game"
# define TILE_WIDTH 32
# define SUCCESS_EXIT 1
# define FAILURE_EXIT 0

typedef struct win_render {
	void	*mlx;
	void	*win;
}	t_win_render;

typedef struct game_set
{
  char	**map;
	int		map_height;
	int		map_length;
	int		player_position_x;
	int		player_position_y;
  int   player_movements;
}	t_game_set;

int ft_start(void);
int	ft_get_map(int argc, char *argv[], t_game_set **game_set);
int	ft_check_file_extension(char *file_name);

#endif
