/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:10:41 by julian            #+#    #+#             */
/*   Updated: 2023/12/22 19:07:15 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void   stack_init(t_list **stack, int argc, char **argv)
{
    int i;
    int num;
    t_list *tmp;

    i = 1;
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    while (i < argc)
    {
        num = ft_atol(argv[i]);
        tmp = ft_lstnew(num);
        ft_lstadd_back(stack, tmp);
        i++;
    }
    check_duplicates(*stack);
    //check_minmax(*stack);
    index_stack(stack);
}

int main(int argc, char **argv)
{
    t_list **stack_a;
    t_list **stack_b;

    
    if (argc < 2)
        return (-1);
    ft_check_args(argc, argv);
    stack_a = (t_list **)malloc(sizeof(t_list));
    stack_b = (t_list **)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
    stack_init(stack_a, argc, argv);
    if (is_sorted(stack_a))
    {
        free_stack(*stack_a);
        free_stack(*stack_b);
        return (0);
    }
    radix_sort(stack_a, stack_b);
    if (argc == 2)
        ft_free(argv);
    free_stack(*stack_a);
    free_stack(*stack_b);
    return (0);
}

