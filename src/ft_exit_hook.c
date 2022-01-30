/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:19:33 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 03:19:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit_hook(t_game_set *game_set)
{
	mlx_destroy_window(game_set->mlx, game_set->win);
	ft_free(game_set);
	exit(0);
}
