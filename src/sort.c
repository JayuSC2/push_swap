/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:00:27 by julian            #+#    #+#             */
/*   Updated: 2023/12/22 19:05:15 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_max_bits(t_list *stack)
{
    int max;
    int max_bits;
    
    max = stack->index;
    max_bits = 0;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
	int i;
	int j;
	int max_bits;

	i = 0;
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < ft_lstsize(*stack_a))
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

/* void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int j;
    int max_bits;
    int size;

    i = 0;
    size = ft_lstsize(*stack_a);
    max_bits = get_max_bits(stack_a);
    while (i < max_bits)
    {
        j = 0;
        while(j++ < size)
        {
            if ((((*stack_a)->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while (ft_lstsize(*stack_b) > 0)
            pa(stack_a, stack_b);
        i++;
    }
}
 */

