/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:00:00 by juitz             #+#    #+#             */
/*   Updated: 2024/03/13 17:05:22 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_stack(t_list **stack)
{
	t_list	*top;
	t_list	*tmp;

	top = *stack;
	if (stack == NULL)
		return ;
	while (top)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
	free(stack);
}
