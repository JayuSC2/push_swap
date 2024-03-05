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

/* static void   stack_init(t_list **stack, int argc, char **argv)
{
    t_list *tmp;
    int i;
    int num;
    
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
 */

t_list	**stack_init(t_list **stack_a, int argc, char **argv)
{
    t_list *new;
	//char **args;
    int i;

    i = 1;
    if (argc == 2)
    {
        i = 0;
    	argv = ft_split(argv[1], ' ');
    }
	/* else if (argc > 2)
		args = argv; */
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (stack_a == NULL)
		return (NULL);
    *stack_a = NULL;
    while (argv[i])
    {
        new = ft_lstnew(ft_atoi(argv[i]));
        ft_lstadd_back(stack_a, new);
        i++;
    }
	if (argc == 2)
    	ft_free(argv);
    index_stack(stack_a);
	return (stack_a);
}

void sort_stack(t_list **stack_a)
{
	t_list	**stack_b;

	if (is_sorted(stack_a) == 1)
	{
		free_stack(stack_a);
		return ;
	}
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (stack_b == NULL)
	{
		free_stack(stack_a);
		return ;
	}
	*stack_b = NULL;
	if (ft_lstsize(*stack_a) > 5)
		radix_sort(stack_a, stack_b);
	else
		smol_sort(stack_a, stack_b);
	free_stack(stack_a);	
	free_stack(stack_b);
}

int main(int argc, char **argv)
{
    t_list **stack_a;
	char	**args;

    if (argc < 2)
    	return (-1);
	else if (argv[1][0] == '\0')
		return (print_error(), -1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (-1);
		if (ft_check_args(argc, args) == 1)
			return (ft_free(args), print_error(), -1);
	}
	if (ft_check_args(argc, argv) == 1)
			return (print_error(), -1);
	stack_a = NULL;
    stack_a = stack_init(stack_a, argc, argv);
	sort_stack(stack_a);
	if (argc == 2)
		ft_free(args);
    //print_stack(*stack_a);
    return (0);
}
