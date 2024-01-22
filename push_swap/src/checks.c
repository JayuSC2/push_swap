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

/* void   check_minmax(t_list *stack)
{
    t_list *tmp;

    tmp = stack;
    while (tmp)
    {
        if (tmp->index > 2147483647 || tmp->index < -2147483648)
            print_error();
        tmp = tmp->next;
    }
} */

void   check_duplicates(t_list *stack)
{
    t_list *tmp;
    t_list *tmp2;

    tmp = stack;
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (tmp->index == tmp2->index)
                print_error();
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
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
}