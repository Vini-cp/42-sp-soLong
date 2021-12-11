#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_set	*game_set;

	if (!ft_get_map(argc, argv, &game_set) || !ft_game_loop(&game_set))
	{
		ft_free(&game_set, game_set->game_window);
		return (FAILURE_EXIT);
	}
	return (SUCCESS_EXIT);
}
