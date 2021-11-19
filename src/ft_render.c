#include "../so_long.h"

static void	ft_put_image(t_win_render *game_window, void *img, int x, int y)
{
	mlx_put_image_to_window(game_window->mlx, game_window->win, img, x, y);
}

void	ft_render(t_game_set *game_set, t_win_render *game_window)
{
	int		x_pos;
	int		y_pos;
  char  map_position;

  mlx_clear_window(game_window->mlx, game_window->win);
  y_pos = 0;
	while (y_pos < game_set->map_height)
	{
		x_pos = 0;
		while (x_pos < game_set->map_length)
		{
			map_position = game_set->map[y_pos][x_pos];
      ft_put_image(game_window, game_set->background, x_pos * TILE_WIDTH, y_pos * TILE_WIDTH);
      if (map_position == '1')
        ft_put_image(game_window, game_set->wall, x_pos * TILE_WIDTH, y_pos * TILE_WIDTH);
      else if (map_position == 'C')
        ft_put_image(game_window, game_set->collectible, x_pos * TILE_WIDTH, y_pos * TILE_WIDTH);
      else if (map_position == 'E')
        ft_put_image(game_window, game_set->exit, x_pos * TILE_WIDTH, y_pos * TILE_WIDTH);
      else if (map_position == 'P')
        ft_put_image(game_window, game_set->player, x_pos * TILE_WIDTH, y_pos * TILE_WIDTH);
			x_pos++;
		}
		y_pos++;
	}
}
