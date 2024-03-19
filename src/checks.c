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
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(int input)
{
	if (input == ' ' || input == '\t' || input == '\n')
		return (1);
	if (input == '\v' || input == '\f' || input == '\r')
		return (1);
	return (0);
}

int	ft_isdupnode(t_list *stack)
{
	t_list	*current;
	t_list	*compare;

	current = stack;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_overflow(int argc, char **argv)
{
	long int	num;
	int			i;

	i = 1;
	if (argc == 2)
		i = 0;
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

	if (argv[i][0] == '\0' || check_overflow(argc, argv) == 1)
		return (1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
			|| ((!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j])
			&& argv[i][j] != '-'))
			|| ((ft_isdigit(argv[i][j]) && argv[i][j + 1] == '-'))
			|| (ft_isspace(argv[i][j]) && ft_isspace(argv[i][j + 1])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
