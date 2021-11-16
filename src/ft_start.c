#include "../so_long.h"

int ft_start(void)
{
    t_win_render    *game_window;

    game_window = malloc(sizeof(game_window));

    if ((game_window->mlx = mlx_init()) == NULL)
        return (FAILURE_EXIT);
    if ((game_window->win = mlx_new_window(game_window->mlx, TILE_WIDTH * 35, TILE_WIDTH * 25, WINDOW_NAME)) == NULL)
        return (FAILURE_EXIT);
    mlx_loop(game_window->mlx);
    return (SUCCESS_EXIT);
}
