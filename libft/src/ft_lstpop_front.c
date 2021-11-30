/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:19:23 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/23 18:44:18 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstpop_front(t_list **lst)
{
	t_list	*next_node;
	int	content;

	next_node = (*lst)->next;
	content = (*lst)->content;
	free(*lst);
	*lst = next_node;
	return content;
}
