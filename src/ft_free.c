/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:13:29 by vcordeir          #+#    #+#             */
/*   Updated: 2022/01/31 01:12:42 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(t_game_set *game_set)
{
	mlx_destroy_image(game_set->mlx, game_set->player);
	mlx_destroy_image(game_set->mlx, game_set->wall);
	mlx_destroy_image(game_set->mlx, game_set->background);
	mlx_destroy_image(game_set->mlx, game_set->exit);
	mlx_destroy_image(game_set->mlx, game_set->collectible);
	mlx_destroy_display(game_set->mlx);
	free(game_set->mlx);
	ft_free_map(game_set);
}
