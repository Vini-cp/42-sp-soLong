#include "../so_long.h"

static void	ft_free_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	ft_free(t_game_set **game_set, t_win_render *game_window)
{
	ft_free_map((*game_set)->map, (*game_set)->map_height);
	(*game_set)->map = NULL;
	free(game_set);
	free(game_window);
}
