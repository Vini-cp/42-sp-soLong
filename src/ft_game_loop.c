#include "../so_long.h"

int ft_game_loop(t_game_set *game_set)
{
  t_win_render *game_window;

  game_window = malloc(sizeof(game_window));

  if ((game_window->mlx = mlx_init()) == NULL)
    return (FAILURE_EXIT);
  if ((game_window->win = mlx_new_window(game_window->mlx, TILE_WIDTH * game_set->map_length, TILE_WIDTH * game_set->map_height, WINDOW_NAME)) == NULL)
    return (FAILURE_EXIT);
  game_set->game_window = game_window;
  ft_build_images(&game_set, &game_window);
  ft_render(game_set, game_window);
	mlx_key_hook(game_window->win, ft_key_hook, &game_set);
	mlx_hook(game_window->win, 17, 0, ft_exit_hook, &game_set);
	mlx_loop(game_window->mlx);
  return (SUCCESS_EXIT);
}
