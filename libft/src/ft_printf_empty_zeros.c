/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_empty_zeros.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:09:28 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/21 20:45:56 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	int	define_just(int width, int just)
{
	if (width < 0)
		return (1);
	return (just);
}

static	int	define_width(int width)
{
	if (width < 0)
		return (width * -1);
	return (width);
}

static	int	define_size(int width, int prec)
{
	if (width >= prec)
		return (width);
	return (prec);
}

void	ft_printf_empty_zeros(t_flags ***lst)
{
	char	*s;
	char	*t;
	int		i;
	int		size;

	(**lst)->just = define_just((**lst)->width, (**lst)->just);
	(**lst)->width = define_width((**lst)->width);
	size = define_size((**lst)->width, (**lst)->prec);
	s = (char *)malloc((size + 1) * sizeof(char));
	t = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		s[i] = '0';
		t[i] = ' ';
		i++;
	}
	s[i] = '\0';
	t[i] = '\0';
	(**lst)->f = ft_strdup(s);
	(**lst)->spaces = ft_strdup(t);
}
