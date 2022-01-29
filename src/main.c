#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_game_set	game_set;

	if (!ft_get_map(argc, argv, &game_set))
		return (ft_exit_error(&game_set, "Error\nMap is misconfigured"));
	if (!ft_set_configs(&game_set))
		return (ft_exit_error(&game_set, "Error\nGame window did not start correctly"));
	if (!ft_game_loop(&game_set))
		return (ft_exit_error(&game_set, "Error\nGame exited!"));	
	return (SUCCESS_EXIT);
}
