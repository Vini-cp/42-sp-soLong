/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:19:31 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 23:03:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit_error(t_game_set *game_set, char *message, void (*f)(t_game_set *))
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	if (game_set != NULL)
		f(game_set);
	return (FAILURE_EXIT);
}
