/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:51:41 by julian            #+#    #+#             */
/*   Updated: 2024/01/21 20:10:00 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_list **stack_a)
{
    int a;
    int b;
    int c;

    a = (*stack_a)->index;
    b = (*stack_a)->next->index;
    c = (*stack_a)->next->next->index;
    if (a > b && b < c && a < c)
        sa(stack_a);
    else if (a > b && b > c && a > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > b && b < c && a > c)
        ra(stack_a);
    else if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);
}

void smol_sort(t_list **stack_a)
{
    int len;

    len = ft_lstsize(*stack_a);
    if (is_sorted(stack_a) || (len < 2))
        return ;
    if (len == 2)
        sa(stack_a);
    else if (len == 3)
        sort_3(stack_a);
   /*  else if (len == 4)
        sort_4(stack_a, stack_b);
    else if (len == 5)
        sort_5(stack_a, stack_b); */
}
