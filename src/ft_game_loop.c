/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:19:52 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 03:19:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_game_loop(t_game_set *game_set)
{
	mlx_key_hook(game_set->win, ft_key_hook, game_set);
	mlx_hook(game_set->win, 17, 0, ft_exit_hook, game_set);
	mlx_loop(game_set->mlx);
	return (SUCCESS_EXIT);
}
