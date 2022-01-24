#include "../so_long.h"

int	ft_exit_hook(t_game_set *game_set)
{
	mlx_destroy_window(game_set->mlx, game_set->win);
	ft_free(game_set);
	exit(0);
}
