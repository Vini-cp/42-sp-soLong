#include "so_long.h"

int main(void)
{
    t_win_render    *game_window;
    game_window = malloc(sizeof(game_window));

    if ((game_window->mlx = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((game_window->win = mlx_new_window(game_window->mlx, 640, 480, "Hello world Vini")) == NULL)
        return (EXIT_FAILURE);
    mlx_loop(game_window->mlx);
    return (EXIT_SUCCESS);
}
