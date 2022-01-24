#include "../so_long.h"

int	ft_game_loop(t_game_set *game_set)
{
	mlx_key_hook(game_set->win, ft_key_hook, game_set);
	mlx_hook(game_set->win, 17, 0, ft_exit_hook, game_set);
	mlx_loop(game_set->mlx);
	return (SUCCESS_EXIT);
}
