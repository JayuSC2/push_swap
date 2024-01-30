/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:51:41 by julian            #+#    #+#             */
/*   Updated: 2024/01/30 14:06:13 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;

	min = NULL;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && (!min || head->value < min->value))
			min = head;
		head = head->next;
	}
	return (min);
} */

t_list	get_smallest(t_list *stack_a)
{
	t_list *tmp;
	tmp = stack_a;

	while (stack_a->next != NULL)
	{ 
		if(stack_a->index > stack_a->next->index)
		{
			tmp->next->index = stack_a->next->index;
			tmp->index = stack_a->index;
			stack_a->index = tmp->next->index;
			stack_a->next->index = tmp->index;
		}
		else
			stack_a = stack_a->next;
	}
	return (*stack_a);
}

void sort_3(t_list **stack_a)
{
    int a;
    int b;
    int c;

    a = (*stack_a)->index;
    b = (*stack_a)->next->index;
    c = (*stack_a)->next->next->index;
    if (a > b && b > c && a > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > b && b < c && a < c)
        sa(stack_a);
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

void sort_4(t_list **stack_a, t_list **stack_b)
{
    int len;
    int i;

    len = ft_lstsize(*stack_a);
    i = 0;
    while (get_smallest(*stack_a) && len == 4)
	//while (i < len - 3)
    {
        pb(stack_b, stack_a);
        i++;
    }
    sort_3(stack_a);
    pa(stack_b, stack_a);
}

void smol_sort(t_list **stack_a, t_list **stack_b)
{
    int len;

    len = ft_lstsize(*stack_a);
    if (is_sorted(stack_a) || (len < 2))
        return ;
    if (len == 2)
        sa(stack_a);
    else if (len == 3)
        sort_3(stack_a);
    else if (len == 4)
        sort_4(stack_a, stack_b);
    /*else if (len == 5)
        sort_5(stack_a, stack_b); */
}
