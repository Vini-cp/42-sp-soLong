/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:19:31 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/21 20:48:17 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void (*f)(int))
{
	t_list	*head;
	t_list	*next_node;

	head = NULL;
	while (lst != NULL)
	{
		next_node = ft_lstnew(f(lst->content));
		if (!next_node)
		{
			while (head)
			{
				next_node = head->next;
				free(head);
				head = next_node;
			}
			return (NULL);
		}
		ft_lstadd_back(&head, next_node);
		lst = lst->next;
	}
	return (head);
}
