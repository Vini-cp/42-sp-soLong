#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "printf/include/printf.h"

# define WINDOW_NAME "soLong game"
# define TILE_WIDTH 80
# define SUCCESS_EXIT 1
# define FAILURE_EXIT 0

# define ESC 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

# define PLAYER "./assets/player.xpm"
# define WALL "./assets/wall.xpm"
# define BACKGROUND "./assets/background.xpm"
# define EXIT "./assets/exit.xpm"
# define COLLECTIBLE "./assets/collectible.xpm"

# define ORANGE 0xFE6500

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
  int   no_collectibles;
  int   no_exits;
  int   game_won;
  void	*player;
  void	*wall;
  void	*background;
	void	*exit;
	void	*collectible;
  t_win_render *game_window;
}	t_game_set;

int ft_game_loop(t_game_set *game_set);
int	ft_get_map(int argc, char *argv[], t_game_set **game_set);
int	ft_check_file_extension(char *file_name);
int	ft_get_info_from_map(t_game_set ***game_set);
int	ft_key_hook(int keycode, t_game_set **game_set);
int	ft_exit_hook(t_game_set **game_set);
void	ft_build_images(t_game_set **game_set, t_win_render **game_window);
void	ft_render(t_game_set *game_set, t_win_render *game_window);
void	ft_free(t_game_set *game_set, t_win_render *game_window);

#endif
