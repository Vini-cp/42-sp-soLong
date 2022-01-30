/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:00:26 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 22:53:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(t_game_set *game_set)
{
	int	i;

	i = 0;
	while (i < game_set->map_height)
	{
		free(game_set->map[i]);
		i++;
	}
	free(game_set->map);
}
