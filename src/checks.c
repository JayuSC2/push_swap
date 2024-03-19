/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:39:17 by julian            #+#    #+#             */
/*   Updated: 2023/12/22 18:58:09 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	isspace(int input)
{
	if (input == ' ' || input == '\t' || input == '\n')
		return (1);
	if (input == '\v' || input == '\f' || input == '\r')
		return (1);
	return (0);
}

int ft_isdupnode(t_list *stack)
{
	t_list *top;
	int stack_size;
	int i;
	int j;

	top = stack;
	stack = stack->next;
	stack_size = ft_lstsize(stack);
	i = 0;

	while (i < stack_size)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if (top->value == stack->value)
				return (1);
			stack = stack->next;
			j++;
		}
		top = top->next;
		i++;
	}
	return (0);
}

/* int	ft_isdup(int argc, char **argv)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (j < argc)
		{
			num1 = ft_atoi(argv[i]);
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
} */

int	check_overflow(int argc, char **argv)
{
	int			i;
	long int	num;

	if (argc == 2)
		i = 0;
	i = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_args(int argc, char **argv, int i)
{
	int	j;
	/* t_list **stack;

	*stack = argv; */
	if (argv[i][0] == '\0' /* || ft_isdupnode(*stack) == 1 */
	|| check_overflow(argc, argv) == 1)
		return (1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' && !isdigit(argv[i][j + 1]))
			|| ((!isdigit(argv[i][j]) && !isspace(argv[i][j])
			&& argv[i][j] != '-'))
			|| ((isdigit(argv[i][j]) && argv[i][j + 1] == '-'))
			|| (isspace(argv[i][j]) && isspace(argv[i][j + 1])))
				return (1);
			j++;
		}
		i++;
	}
/* 	if (isdup(argv) == true)
		return (1); */
	return (0);
}

/*  if (ft_isdigit(argv[i][j]) && argv[i][j + 1] == '+')
				return (1); */