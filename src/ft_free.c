/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:13:29 by vcordeir          #+#    #+#             */
/*   Updated: 2022/01/24 09:27:48 by vcordeir         ###   ########.fr       */
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

void	ft_free(t_game_set *game_set)
{
	mlx_destroy_image(game_set->mlx, game_set->player);
	mlx_destroy_image(game_set->mlx, game_set->wall);
	mlx_destroy_image(game_set->mlx, game_set->background);
	mlx_destroy_image(game_set->mlx, game_set->exit);
	mlx_destroy_image(game_set->mlx, game_set->collectible);
	ft_free_map(game_set->map, game_set->map_height);
	// mlx_destroy_window(game_set->mlx, game_set->win);
	// mlx_destroy_display(game_set->mlx);
	free(game_set->mlx);
}
