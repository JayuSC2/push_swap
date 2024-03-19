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

/* int   swap_both(t_list **stack1, t_list **stack2)
{
	swap(stack1);
	swap(stack2);
	ft_putendl_fd("ss", 1);
	return (0);
}

int   rotate_both(t_list **stack1, t_list **stack2)
{
	rotate(stack1);
	rotate(stack2);
	ft_putendl_fd("rr", 1);
	return (0);
}

int   reverse_rotate_both(t_list **stack1, t_list **stack2)
{
	rr(stack1);
	rr(stack2);
	ft_putendl_fd("rrr", 1);
	return (0);
}
 */
/* int swap(t_list **stack)
{
	t_list *tmp;
	t_list *head;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = *stack;
		*stack = tmp;
	}
	return (0);
} */

/* int   rotate(t_list **stack)
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
} */