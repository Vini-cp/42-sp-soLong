#include "../so_long.h"

int ft_set_configs(t_game_set *game_set)
{
	game_set->mlx = mlx_init();
	if (game_set->mlx == NULL)
		return (FAILURE_EXIT);
	game_set->win = mlx_new_window(game_set->mlx, 
			TILE_WIDTH * game_set->map_length, 
			TILE_WIDTH * game_set->map_height, WINDOW_NAME);
	if (game_set->win == NULL)
		return (FAILURE_EXIT);
	ft_build_images(game_set);
	ft_render(game_set);
	return (SUCCESS_EXIT);
}
