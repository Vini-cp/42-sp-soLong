/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_extension.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 03:19:28 by coder             #+#    #+#             */
/*   Updated: 2022/01/30 03:19:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_file_extension(char *file_name)
{
	char	*extension;

	extension = (char *) &file_name[(ft_strlen(file_name) - 4)];
	if (ft_strncmp(extension, ".ber", 4) == 0)
		return (SUCCESS_EXIT);
	return (FAILURE_EXIT);
}
