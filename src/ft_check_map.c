/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:05:36 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 23:11:49 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_first_last_row(char *row)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(row);
	while (i < length)
	{
		if (row[i] != '1')
			return (FAILURE_EXIT);
		i++;
	}
	return (SUCCESS_EXIT);
}

static int	check_middle_row(char *row)
{
	int	i;
	int	length;

	i = 1;
	length = ft_strlen(row);
	if (row[0] != '1' || row[length - 1] != '1')
		return (FAILURE_EXIT);
	while (i < length - 1)
	{
		if (row[i] != 'C' && row[i] != 'E' && row[i] != 'P'
			&& row[i] != '0' && row[i] != '1')
			return (FAILURE_EXIT);
		i++;
	}
	return (SUCCESS_EXIT);
}

int	ft_check_map(t_game_set *game_set)
{
	int	size;

	size = 0;
	game_set->map_length = ft_strlen(game_set->map[size]);
	while (size < game_set->map_height)
	{	
		if (game_set->map_length != (int) ft_strlen(game_set->map[size]))
			return (FAILURE_EXIT);
		if (size == 0 || size == game_set->map_height - 1)
		{
			if (!check_first_last_row(game_set->map[size]))
				return (FAILURE_EXIT);
		}
		else
		{
			if (!check_middle_row(game_set->map[size]))
				return (FAILURE_EXIT);
		}
		size++;
	}
	return (SUCCESS_EXIT);
}
