#include "../so_long.h"

int ft_exit_error(t_game_set *game_set, char *message)
{
	ft_free(game_set);
	ft_printf("%s\n", message);
	return (FAILURE_EXIT);
}
