/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:17:37 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 23:14:05 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_game_set	game_set;

	if (!ft_get_map(argc, argv, &game_set))
		return (ft_exit_error(NULL, "Error\nCheck your arguments", NULL));
	if (!ft_check_map(&game_set))
		return (ft_exit_error(&game_set, "Error\nMap problem", ft_free_map));
	if (!ft_set_configs(&game_set))
		return (ft_exit_error(&game_set, "Error\nGame win problem", ft_free));
	if (!ft_game_loop(&game_set))
		return (ft_exit_error(&game_set, "Error\nGame exited!", ft_free));
	return (SUCCESS_EXIT);
}
