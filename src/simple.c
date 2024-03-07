/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:51:41 by julian            #+#    #+#             */
/*   Updated: 2024/03/07 15:55:05 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_smallest(t_list **stack_a)
{
	t_list	*current;
	t_list	*smallest;

	current = *stack_a;
	smallest = *stack_a;
	while (current != NULL)
	{
		if (current->index < smallest->index)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

void	sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

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

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		smallest_pos;
	t_list	*smallest;
	t_list	*current;

	i = 0;
	smallest_pos = 0;
/* 	len = ft_lstsize(*stack_a);
	if (len < 1)
		return; */
	smallest = get_smallest(stack_a);
	current = *stack_a;
	while (current && current != smallest)
	{
		if (current == smallest)
			break ;
		current = current->next;
		smallest_pos++;
	}
	while (i++ < smallest_pos)
		ra(stack_a);
	pb(stack_b, stack_a);
	sort_3(stack_a);
	if (stack_b)
		pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		smallest_pos;
	t_list	*smallest;
	t_list	*current;

	i = 0;
	smallest_pos = 0;
/* 	len = ft_lstsize(*stack_a);
	if (len < 1)
		return; */
	smallest = get_smallest(stack_a);
	current = *stack_a;
	while (current && current != smallest)
	{
		if (current == smallest)
			break ;
		current = current->next;
		smallest_pos++;
	}
	while (i++ < smallest_pos)
		ra(stack_a);
	pb(stack_b, stack_a);
	sort_4(stack_a, stack_b);
	if (stack_b)
		pa(stack_a, stack_b);
}

void	smol_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (is_sorted(stack_a) || (len < 2))
		return ;
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else if (len == 5)
		sort_5(stack_a, stack_b);
}
/* t_list	*get_next_min(t_list **stack)
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