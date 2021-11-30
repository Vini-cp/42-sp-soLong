/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_newflag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:09:34 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/21 20:45:47 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_flags	*ft_printf_newflag(void)
{
	t_flags	*lst;

	lst = (t_flags *)malloc(sizeof(t_flags));
	lst->f = NULL;
	lst->str = NULL;
	lst->spaces = NULL;
	lst->just = 0;
	lst->prec = -1;
	lst->width = 0;
	lst->zero = 0;
	return (lst);
}
