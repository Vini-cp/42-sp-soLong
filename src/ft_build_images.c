/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:19:25 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 03:19:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_to_image(void **img, char *img_name, t_game_set *game_set)
{
	*img = mlx_xpm_file_to_image(game_set->mlx,
			img_name, &game_set->img_width, &game_set->img_height);
}

void	ft_build_images(t_game_set *game_set)
{
	ft_to_image(&game_set->player, PLAYER, game_set);
	ft_to_image(&game_set->wall, WALL, game_set);
	ft_to_image(&game_set->background, BACKGROUND, game_set);
	ft_to_image(&game_set->exit, EXIT, game_set);
	ft_to_image(&game_set->collectible, COLLECTIBLE, game_set);
}
