#include "../so_long.h"

int	ft_exit_hook(t_game_set **game_set)
{
	ft_free(game_set, (*game_set)->game_window);
	exit(0);
}
