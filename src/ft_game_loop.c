#include "../so_long.h"

int	ft_game_loop(t_game_set **game_set)
{
	int	len;
	int	hgt;
	t_win_render	*game_window;

	len = TILE_WIDTH * (*game_set)->map_length;
	hgt = TILE_WIDTH * (*game_set)->map_height;
	game_window = malloc(sizeof(game_window));
	game_window->mlx = mlx_init();
	if (game_window->mlx == NULL)
		return (FAILURE_EXIT);
	game_window->win = mlx_new_window(game_window->mlx, len, hgt, WINDOW_NAME);
	if (game_window->win == NULL)
		return (FAILURE_EXIT);
	(*game_set)->game_window = game_window;
	ft_build_images(game_set, &game_window);
	ft_render(game_set, game_window);
	mlx_key_hook(game_window->win, ft_key_hook, game_set);
	mlx_hook(game_window->win, 17, 0, ft_exit_hook, game_set);
	mlx_loop(game_window->mlx);
	return (SUCCESS_EXIT);
}
