/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:13:29 by vcordeir          #+#    #+#             */
/*   Updated: 2022/01/02 21:14:10 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free_map(char **map, int map_len)
{
	int	i;

	i = 0;
	while (i < map_len)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free(t_game_set **game_set, t_win_render *game_window)
{
	ft_free_map((*game_set)->map, (*game_set)->map_height);
	free(*game_set);
	free(game_window);
}
