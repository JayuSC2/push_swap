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

void   print_error(void)
{
    ft_putendl_fd("Error", 2);
    exit(1);
}

int	ft_isspace(int input)
{
	if (input == ' ' || input == '\t' || input == '\n' || input == '\v' || input == '\f' || input == '\r')
		return (1);
	return (0);
}

void   check_duplicates(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
                print_error();
            j++;
        }
        i++;
    }
}

void	check_overflow(int argc, char **argv)
{
	int i;
	char *converted;
	int num;
	
	i = 0;
	num = ft_atoi(argv[i]);
	converted = ft_itoa(num);
	while (i < argc)
	{
		if (ft_strncmp(num, converted, 10) != 0)
			print_error();
		/* if (ft_atoi(argv[i]) >= INT_MIN)
			print_error(); */
		i++;
	}
} 

void   ft_check_args(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isspace(argv[i][j]) && ft_isspace(argv[i][j + 1]))
                print_error();
            if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
                print_error();
            if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j]) && argv[i][j] != '-')
                print_error();
            if (ft_isdigit(argv[i][j]) && argv[i][j + 1] == '-')
                print_error();
            if (ft_isdigit(argv[i][j]) && argv[i][j + 1] == '+')
                print_error();
            j++;
        }
        i++;
    }
	check_duplicates(argc, argv);
	//check_minmax(argc, argv);
	//check_overflow(argc, argv);
}

