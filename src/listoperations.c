/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:42:50 by marvin            #+#    #+#             */
/*   Updated: 2023/12/27 14:42:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *stack)
{
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (stack->next == NULL)
			return (stack);
	}
	return (stack);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last_element;

	if (*stack)
	{
		last_element = ft_lstlast(*stack);
		last_element->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}
