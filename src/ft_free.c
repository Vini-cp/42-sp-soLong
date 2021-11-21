#include "../so_long.h"

static void	ft_free_map(char ***map, int size)
{
	int	it;

	it = 0;
	while (it < size)
	{
		free((*map)[it]);
		it++;
	}
	free((*map));
	(*map) = NULL;
}

void	ft_free(t_game_set *game_set, t_win_render *game_window)
{
  ft_free_map(&(game_set->map), game_set->map_height);
  free(game_set);
  free(game_window);
}
