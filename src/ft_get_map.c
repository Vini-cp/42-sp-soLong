/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:20:33 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 22:08:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_check_file_extension(char *file_name)
{
	char	*extension;

	extension = (char *) &file_name[(ft_strlen(file_name) - 4)];
	if (ft_strncmp(extension, ".ber", 4) == 0)
		return (SUCCESS_EXIT);
	return (FAILURE_EXIT);
}

static int	get_nbr_of_lines(char *fn)
{
	int		fd;
	int		out_read;
	int		height;
	char	*row;

	out_read = 1;
	height = 0;
	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (height);
	while (out_read == 1)
	{
		out_read = get_next_line(fd, &row);
		free(row);
		height++;
	}
	close(fd);
	return (height);
}

static int	ft_read_map(char *fn, t_game_set *game_set)
{
	int		fd;
	int		out_read;
	int		row;

	game_set->map_height = get_nbr_of_lines(fn);
	fd = open(fn, O_RDONLY);
	if (fd < 0 || game_set->map_height == 0)
		return (FAILURE_EXIT);
	game_set->map = malloc(sizeof(char **) * game_set->map_height);
	if (!(game_set->map))
		return (FAILURE_EXIT);
	row = 0;
	out_read = 1;
	while (out_read == 1)
	{
		out_read = get_next_line(fd, &game_set->map[row]);
		row++;
	}
	close(fd);
	return (SUCCESS_EXIT);
}

int	ft_get_map(int argc, char *argv[], t_game_set *game_set)
{
	if (argc == 2 && ft_check_file_extension(argv[1]))
	{
		if (!ft_read_map(argv[1], game_set))
			return (FAILURE_EXIT);
		return (SUCCESS_EXIT);
	}
	return (FAILURE_EXIT);
}
