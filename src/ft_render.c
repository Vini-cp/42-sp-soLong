#include "../so_long.h"

static void	ft_put_image(t_game_set *game_set, void *img, int x, int y)
{
	mlx_put_image_to_window(game_set->mlx, game_set->win, img, x, y);
}

static void	ft_render_exit(t_game_set *game_set)
{
	mlx_string_put(game_set->mlx, game_set->win,
		(game_set->map_length / 2) * TILE_WIDTH,
		(game_set->map_height / 2) * TILE_WIDTH, ORANGE, "You win!");
}

static void	ft_render_image(t_game_set *game_set, int x, int y)
{
	char	map_pos;

	map_pos = game_set->map[y][x];
	x *= TILE_WIDTH;
	y *= TILE_WIDTH;
	ft_put_image(game_set, game_set->background, x, y);
	if (map_pos == '1')
		ft_put_image(game_set, game_set->wall, x, y);
	else if (map_pos == 'C')
		ft_put_image(game_set, game_set->collectible, x, y);
	else if (map_pos == 'S' || map_pos == 'E' || map_pos == 'P')
	{
		if (map_pos == 'E' || map_pos == 'S')
			ft_put_image(game_set, game_set->exit, x, y);
		if (map_pos == 'P' || map_pos == 'S')
			ft_put_image(game_set, game_set->player, x, y);
	}
}

static void	ft_render_game(t_game_set *game_set)
{
	int		x_pos;
	int		y_pos;

	y_pos = 0;
	while (y_pos < game_set->map_height)
	{
		x_pos = 0;
		while (x_pos < game_set->map_length)
		{
			ft_render_image(game_set, x_pos, y_pos);
			x_pos++;
		}
		y_pos++;
	}
}

void	ft_render(t_game_set *game_set)
{
	mlx_clear_window(game_set->mlx, game_set->win);
	if (game_set->game_won == 1)
		ft_render_exit(game_set);
	else
		ft_render_game(game_set);
}
