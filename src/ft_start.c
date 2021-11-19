#include "../so_long.h"

int ft_start(t_game_set *game_set)
{
  t_win_render *game_window;

  game_window = malloc(sizeof(game_window));

  if ((game_window->mlx = mlx_init()) == NULL)
    return (FAILURE_EXIT);
  if ((game_window->win = mlx_new_window(game_window->mlx, TILE_WIDTH * game_set->map_length, TILE_WIDTH * game_set->map_height, WINDOW_NAME)) == NULL)
    return (FAILURE_EXIT);
  ft_build_images(&game_set, &game_window);
  ft_render(game_set, game_window);
  mlx_loop(game_window->mlx);
  return (SUCCESS_EXIT);
}
