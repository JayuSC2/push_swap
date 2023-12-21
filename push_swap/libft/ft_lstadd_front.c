/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:40:38 by juitz             #+#    #+#             */
/*   Updated: 2023/11/09 14:01:27 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if(lst != NULL)
	{
		t_list	*old_first_element;
		old_first_element = *lst; 
		new->next = old_first_element;
		*lst = new;
	}
}	
