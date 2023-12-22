/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:10:41 by julian            #+#    #+#             */
/*   Updated: 2023/12/22 18:35:57 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void   print_error(void)
{
    ft_putendl_fd("Error", 2);
    exit(1);
}

static void   check_args(int argc, char **argv)
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
            j++;
        }
        i++;
    }
}

static void   check_integers(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp)
    {
        if (tmp->value > 2147483647 || tmp->value < -2147483648)
            print_error();
        tmp = tmp->next;
    }
}

