#include "../so_long.h"

static void	ft_update_player_position(t_game_set **game_set, int x, int y)
{
	int	p_x;
	int	p_y;

	p_x = (*game_set)->player_position_x;
	p_y = (*game_set)->player_position_y;
	if ((*game_set)->map[p_y][p_x] == 'S')
		(*game_set)->map[p_y][p_x] = 'E';
	else
		(*game_set)->map[p_y][p_x] = '0';
	if ((*game_set)->map[y][x] == 'E')
		(*game_set)->map[y][x] = 'S';
	else
		(*game_set)->map[y][x] = 'P';
	(*game_set)->player_position_x = x;
	(*game_set)->player_position_y = y;
	(*game_set)->player_movements++;
	ft_printf("No of movements: %d\n", (*game_set)->player_movements);
}

static void	ft_move_player(t_game_set **game_set, int x, int y)
{
	int		new_x_position;
	int		new_y_position;
	char	tile_type;

	new_x_position = x + (*game_set)->player_position_x;
	new_y_position = y + (*game_set)->player_position_y;
	tile_type = (*game_set)->map[new_y_position][new_x_position];
	if (tile_type != '1')
	{
		ft_update_player_position(game_set, new_x_position, new_y_position);
		if (tile_type == 'C')
			(*game_set)->no_collectibles--;
		else if (tile_type == 'E' && (*game_set)->no_collectibles == 0)
			(*game_set)->game_won = 1;
	}
}

int	ft_key_hook(int keycode, t_game_set **game_set)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(((*game_set)->game_window)->mlx,
			((*game_set)->game_window)->win);
		ft_free(game_set, (*game_set)->game_window);
		exit(SUCCESS_EXIT);
	}
	if (!(*game_set)->game_won)
	{
		if (keycode == UP)
			ft_move_player(game_set, 0, -1);
		else if (keycode == DOWN)
			ft_move_player(game_set, 0, 1);
		else if (keycode == LEFT)
			ft_move_player(game_set, -1, 0);
		else if (keycode == RIGHT)
			ft_move_player(game_set, 1, 0);
	}
	ft_render(game_set, (*game_set)->game_window);
	return (SUCCESS_EXIT);
}
