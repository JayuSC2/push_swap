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

/* int swap(t_stack **stack)
{
    t_stack *tmp;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    if (*stack && (*stack)->next)
    {
        tmp = (*stack)->next;
        (*stack)->next = tmp->next;
        tmp->next = *stack;
        *stack = tmp;
    }
} */
void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int swap(t_list **stack)
{
    if (ft_lstsize(*stack) < 2)
        return (-1);

    t_list *head = *stack;
    t_list *next = head->next;

    if (!head || !next)
        print_error();

    ft_swap(&head->value, &next->value);
    ft_swap(&head->index, &next->index);

    return (0);
}

int sa(t_list **stack_a)
{
    swap(stack_a);
    if (swap(stack_a) == -1)
        return (-1);
    ft_putendl_fd("sa", 1);
    return (0);
}

int sb(t_list **stack_b)
{
    swap(stack_b);
    if (swap(stack_b) == -1)
        return (-1);
    ft_putendl_fd("sb", 1);
    return (0);
}

int  push(t_list **stack1, t_list **stack2)
{
    t_list *tmp;

    if (!*stack2)
        return (-1);
    tmp = *stack2;
    *stack2 = (*stack2)->next;
    tmp->next = *stack1;
    *stack1 = tmp;
    return (0);
}

int pa(t_list **stack_a, t_list **stack_b)
{
    if (push(stack_a, stack_b) == -1)
        return (-1);
    push(stack_a, stack_b);
    ft_putendl_fd("pa", 1);
    return (0);
}

int pb(t_list **stack_b, t_list **stack_a)
{
    if (push(stack_b, stack_a) == -1)
        return (-1);
    push(stack_b, stack_a);
    ft_putendl_fd("pb", 1);
    return (0);
}

int   rotate(t_list **stack)
{
    t_list *tmp;
    t_list *tmp2;

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
    return (0);
}

int ra(t_list **stack_a)
{
    if (rotate(stack_a) == -1)
        return (-1);
    ft_putendl_fd("ra", 1);
    return (0);
}

int rb(t_list **stack_b)
{
    if (rotate(stack_b) == -1)
        return (-1);
    rotate(stack_b);
    ft_putendl_fd("rb", 1);
    return (0);
}

void    reverse_rotate(t_list **stack)
{
    t_list *tmp;
    t_list *tmp2;

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

int reverse_rotate_a(t_list **stack_a)
{
    reverse_rotate(stack_a);
    ft_putendl_fd("rra", 1);
    return (0);
}

int reverse_rotate_b(t_list **stack_b)
{
    reverse_rotate(stack_b);
    ft_putendl_fd("rrb", 1);
    return (0);
}

int   swap_both(t_list **stack1, t_list **stack2)
{
    swap(stack1);
    swap(stack2);
    ft_putendl_fd("ss", 1);
    return (0);
}

int    rotate_both(t_list **stack1, t_list **stack2)
{
    rotate(stack1);
    rotate(stack2);
    ft_putendl_fd("rr", 1);
    return (0);
}

int   reverse_rotate_both(t_list **stack1, t_list **stack2)
{
    reverse_rotate(stack1);
    reverse_rotate(stack2);
    ft_putendl_fd("rrr", 1);
    return (0);
}
