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

//#include <limits.h>
#include "push_swap.h"
//#include <stdio.h>

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
}

int	is_number(char *str)
{
	
}

int	ft_isspace(int input)
{
	if (input == ' ' || input == '\t' || input == '\n')
		return (1);
	if (input == '\v' || input == '\f' || input == '\r')
		return (1);
	return (0);
}

/* int	ft_isdup(int argc, char **argv)
{
	int	i;
	int	j;
	int num1;
	int num2;

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

int	ft_isdup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '\0')
				return (1);
			if (argv[i][j] == '-' && !isdigit(argv[i][j + 1]))
				return (1);
			if (!isdigit(argv[i][j]) && !ft_isspace(argv[i][j]) && argv[i][j] != '-')
				return (1);
			if (isdigit(argv[i][j]) && argv[i][j + 1] == '-')
				return (1);
			/* if (ft_isspace(argv[i][j]) && ft_isspace(argv[i][j + 1]))
                return (1); */
			j++;
		}
		i++;
		if (ft_isdup(argc, argv) == 1 || check_overflow(argc, argv) == 1)
			return (1);
	}
	return (0);
}

/*  if (ft_isdigit(argv[i][j]) && argv[i][j + 1] == '+')
                return (1); */