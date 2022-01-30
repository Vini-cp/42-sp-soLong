/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_configs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:20:12 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 23:00:09 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_set_configs(t_game_set *game_set)
{
	game_set->mlx = mlx_init();
	if (game_set->mlx == NULL)
		return (FAILURE_EXIT);
	game_set->win = mlx_new_window(game_set->mlx,
			TILE_WIDTH * game_set->map_length,
			TILE_WIDTH * game_set->map_height, WINDOW_NAME);
	if (game_set->win == NULL)
		return (FAILURE_EXIT);
	ft_build_images(game_set);
	ft_get_info_from_map(game_set);
	ft_render(game_set);
	return (SUCCESS_EXIT);
}
