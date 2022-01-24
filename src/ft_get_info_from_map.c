#include "../so_long.h"

static void	ft_set_player_position(t_game_set *game_set, int x, int y)
{
	game_set->player_position_x = x;
	game_set->player_position_y = y;
}

static void	ft_set_initial_variables(t_game_set *game_set)
{
	game_set->no_exits = 0;
	game_set->no_collectibles = 0;
	game_set->player_movements = 0;
	game_set->game_won = 0;
	game_set->player_position_x = 0;
	game_set->player_position_y = 0;
}

int	ft_get_info_from_map(t_game_set *game_set)
{
	int	x_pos;
	int	y_pos;

	ft_set_initial_variables(game_set);
	y_pos = 0;
	while (y_pos < game_set->map_height)
	{
		x_pos = 0;
		while (x_pos < game_set->map_length)
		{
			if (game_set->map[y_pos][x_pos] == 'C')
				game_set->no_collectibles++;
			else if (game_set->map[y_pos][x_pos] == 'E')
				game_set->no_exits++;
			else if (game_set->map[y_pos][x_pos] == 'P')
				ft_set_player_position(game_set, x_pos, y_pos);
			x_pos++;
		}
		y_pos++;
	}
	if (game_set->no_collectibles == 0 || game_set->no_exits == 0
		|| game_set->player_position_x == 0
		|| game_set->player_position_y == 0)
		return (FAILURE_EXIT);
	return (SUCCESS_EXIT);
}
