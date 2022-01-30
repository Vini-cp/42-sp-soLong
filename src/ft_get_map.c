/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:20:33 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 03:22:58 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_first_last_row(char *row, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (row[i] != '1')
			return (FAILURE_EXIT);
		i++;
	}
	return (SUCCESS_EXIT);
}

static int	check_first_last_column(char *row, int size)
{
	if (row[0] != '1' || row[size - 1] != '1')
		return (FAILURE_EXIT);
	return (SUCCESS_EXIT);
}

static int	check_map_conditions(char *fn, int *h, int *l)
{
	int		fd;
	int		out_read;
	char	*row;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		return (FAILURE_EXIT);
	out_read = get_next_line(fd, &row);
	*l = (int) ft_strlen(row);
	*h = 1;
	if (!check_first_last_row(row, *l))
		return (FAILURE_EXIT);
	while (out_read == 1)
	{
		free(row);
		out_read = get_next_line(fd, &row);
		if (!check_first_last_column(row, *l) || *l != (int) ft_strlen(row))
			return (FAILURE_EXIT);
		*h += 1;
	}
	if (!check_first_last_row(row, *l))
		return (FAILURE_EXIT);
	close(fd);
	free(row);
	return (SUCCESS_EXIT);
}

static int	ft_read_map(char *fn, t_game_set *game_set)
{
	int		fd;
	int		out_read;
	int		row;

	if (!check_map_conditions(fn, &game_set->map_height,
			&game_set->map_length))
		return (FAILURE_EXIT);
	fd = open(fn, O_RDONLY);
	if (fd < 0)
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
		if (!ft_get_info_from_map(game_set))
			return (FAILURE_EXIT);
		return (SUCCESS_EXIT);
	}
	return (FAILURE_EXIT);
}
