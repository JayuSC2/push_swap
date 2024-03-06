/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listdelete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:42:55 by juitz             #+#    #+#             */
/*   Updated: 2024/03/06 16:44:46 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current_node;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		current_node = *lst;
		if (current_node != NULL)
			ft_lstdelone(lst, current_node);
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list **lst, t_list *node)
{
	t_list	*to_delete;

    if (*lst == NULL)
        return ;
    if (node != NULL)
    {
        to_delete = node;
        node = node->next;
        free(to_delete);
        *lst = node;
    }
}