/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:19:31 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 03:20:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit_error(t_game_set *game_set, char *message)
{
	ft_free(game_set);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	return (FAILURE_EXIT);
}
