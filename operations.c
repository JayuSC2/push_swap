/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:58:45 by julian            #+#    #+#             */
/*   Updated: 2023/12/22 18:49:08 by julian           ###   ########.fr       */
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

int sa(t_stack **stack_a)
{
    swap(stack_a);
    ft_putendl_fd("sa\n", 1);
    return (0);
}

int sb(t_stack **stack_b)
{
    swap(stack_b);
    ft_putendl_fd("sb\n", 1);
    return (0);
}

void   push(t_stack **stack1, t_stack **stack2)
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

int pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_putendl_fd("pa\n", 1);
    return (0);
}

int pb(t_stack **stack_b, t_stack **stack_a)
{
    push(stack_b, stack_a);
    ft_putendl_fd("pb\n", 1);
    return (0);
}

void   rotate(t_stack **stack)
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
}

int ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putendl_fd("ra\n", 1);
    return (0);
}

int rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putendl_fd("rb\n", 1);
    return (0);
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

int reverse_rotate_a(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_putendl_fd("rra\n", 1);
    return (0);
}

int reverse_rotate_b(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_putendl_fd("rrb\n", 1);
    return (0);
}

int   swap_both(t_stack **stack1, t_stack **stack2)
{
    swap(stack1);
    swap(stack2);
    ft_putendl_fd("ss\n", 1);
    return (0);
}

int    rotate_both(t_stack **stack1, t_stack **stack2)
{
    rotate(stack1);
    rotate(stack2);
    ft_putendl_fd("rr\n", 1);
}

int   reverse_rotate_both(t_stack **stack1, t_stack **stack2)
{
    reverse_rotate(stack1);
    reverse_rotate(stack2);
    ft_putendl_fd("rrr\n", 1);
}

void    print_stack(t_stack *stack)
{
    while (stack)
    {
        ft_printf("%d\n", stack->value);
        stack = stack->next;
    }
}

