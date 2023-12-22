/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:58:45 by julian            #+#    #+#             */
/*   Updated: 2023/12/21 21:07:10 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack **stack)
{
    t_stack *tmp;

    if (*stack && (*stack)->next)
    {
        tmp = (*stack)->next;
        (*stack)->next = tmp->next;
        tmp->next = *stack;
        *stack = tmp;
    }
}
void    push(t_stack **stack1, t_stack **stack2)
{
    t_stack *tmp;

    if (*stack1)
    {
        tmp = *stack1;
        *stack1 = (*stack1)->next;
        tmp->next = *stack2;
        *stack2 = tmp;
    }
} 
