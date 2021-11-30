/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:26:52 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/23 18:45:50 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_lstpop_back(t_list **lst)
{
	int	content;

	if ((*lst)->next == NULL)
	{
		content = (*lst)->content;
		*lst = NULL;
	}
	else
	{  
		t_list *tmp = *lst;
		while(tmp->next->next != NULL)
			tmp = tmp->next;

		t_list *last_node = tmp->next;
		content = last_node->content;
		tmp->next = NULL;
		free(last_node);
	}
	return content;
}
