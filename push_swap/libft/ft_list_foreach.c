/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:24:30 by julian            #+#    #+#             */
/*   Updated: 2023/12/21 19:24:30 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *list_pointer;
    list_pointer = begin_list;
    
    while (list_pointer)
    {
        (*f)(list_pointer->data);
        list_pointer = list_pointer->next;
    }
}

