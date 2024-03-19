/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:58:06 by juitz             #+#    #+#             */
/*   Updated: 2024/03/19 13:09:50 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

void	rr(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

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

int	rra(t_list **stack_a)
{
	rr(stack_a);
	ft_putendl_fd("rra", 1);
	return (0);
}

/* int rrb(t_list **stack_b)
{
	rr(stack_b);
	ft_putendl_fd("rrb", 1);
	return (0);
} */

/* int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
} */
