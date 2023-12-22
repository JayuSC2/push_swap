/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:58:45 by julian            #+#    #+#             */
/*   Updated: 2023/12/22 13:43:43 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    swap(t_stack **stack)
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

int   push(t_stack **stack1, t_stack **stack2)
{
    t_stack *tmp;

    if (*stack1)
    {
        tmp = *stack1;
        *stack1 = (*stack1)->next;
        tmp->next = *stack2;
        *stack2 = tmp;
    }
    ft_putendl_fd("pb", 1);
}

int   rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tmp2;

    if (*stack && (*stack)->next)
    {
        tmp = *stack;
        tmp2 = *stack;
        *stack = (*stack)->next;
        while (tmp2->next)
            tmp2 = tmp2->next;
        tmp2->next = tmp;
        tmp->next = NULL;
    }
    ft_putendl_fd("ra", 1);
}

void    reverse_rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tmp2;

    if (*stack && (*stack)->next)
    {
        tmp = *stack;
        while (tmp->next->next)
            tmp = tmp->next;
        tmp2 = tmp->next;
        tmp->next = NULL;
        tmp2->next = *stack;
        *stack = tmp2;
    }
}

void    swap_both(t_stack **stack1, t_stack **stack2)
{
    swap(stack1);
    swap(stack2);
}

void    push_both(t_stack **stack1, t_stack **stack2)
{
    push(stack1, stack2);
    push(stack2, stack1);
}

void    rotate_both(t_stack **stack1, t_stack **stack2)
{
    rotate(stack1);
    rotate(stack2);
}

void    reverse_rotate_both(t_stack **stack1, t_stack **stack2)
{
    reverse_rotate(stack1);
    reverse_rotate(stack2);
}

void    print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

