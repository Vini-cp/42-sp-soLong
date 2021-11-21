#include "../so_long.h"

static void	ft_put_image(t_win_render *game_window, void *img, int x, int y)
{
	mlx_put_image_to_window(game_window->mlx, game_window->win, img, x, y);
}

static void ft_render_exit(t_game_set *game_set, t_win_render *game_window)
{
  mlx_string_put(game_window->mlx, game_window->win, (game_set->map_length / 2) * TILE_WIDTH, (game_set->map_height / 2) * TILE_WIDTH, ORANGE, "You win!");
}

static void ft_render_game(t_game_set *game_set, t_win_render *game_window)
{
  int		x_pos;
	int		y_pos;
  char  map_position;

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
      else if (map_position == 'S')
      {
        ft_put_image(game_window, game_set->exit, x_pos * TILE_WIDTH, y_pos * TILE_WIDTH);
        ft_put_image(game_window, game_set->player, x_pos * TILE_WIDTH, y_pos * TILE_WIDTH);
      }
			x_pos++;
		}
		y_pos++;
	}
}

void	ft_render(t_game_set *game_set, t_win_render *game_window)
{
  mlx_clear_window(game_window->mlx, game_window->win);
  if (game_set->game_won == 1)
    ft_render_exit(game_set, game_window);
  else
    ft_render_game(game_set, game_window);
}
