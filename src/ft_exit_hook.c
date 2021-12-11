#include "../so_long.h"

int	ft_exit_hook(t_game_set **game_set)
{
	mlx_destroy_window(((*game_set)->game_window)->mlx,
			((*game_set)->game_window)->win);
	ft_free(game_set, (*game_set)->game_window);
	exit(0);
}
