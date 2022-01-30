/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:13:29 by vcordeir          #+#    #+#             */
/*   Updated: 2022/01/30 03:19:40 by coder            ###   ########.fr       */
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
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	ft_free(t_game_set *game_set)
{
	mlx_destroy_image(game_set->mlx, game_set->player);
	mlx_destroy_image(game_set->mlx, game_set->wall);
	mlx_destroy_image(game_set->mlx, game_set->background);
	mlx_destroy_image(game_set->mlx, game_set->exit);
	mlx_destroy_image(game_set->mlx, game_set->collectible);
	mlx_destroy_display(game_set->mlx);
	free(game_set->mlx);
	ft_free_map(game_set->map, game_set->map_height);
}
