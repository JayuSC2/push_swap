/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:08:49 by julian            #+#    #+#             */
/*   Updated: 2023/12/22 18:36:31 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_list *stack)
{
    while (stack)
    {
        ft_putnbr_fd (stack->value, 1);
		ft_putchar_fd(' ', 1);
        stack = stack->next;
    }
}

int	is_sorted(t_list **stack)
{
	t_list	*top;

	top = *stack;
	while (top && top->next)
	{
		if (top->value > top->next->value)
			return (0);
		top = top->next;
	}
	return (1);
}

void ft_free(char **str)
{
	int i;

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


long int	ft_atol(const char *str)
{
	int			i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	//printf("%s\n", str);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		//printf("num: %li\n", num);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

int ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

