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

t_list	**stack_init(t_list **stack_a, int argc, char **argv)
{
	t_list	*new;
	int		i;

	i = 1;
	if (ft_check_args(argc, argv, 1) == 1)
		return (print_error(), NULL);
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (stack_a == NULL)
		return (NULL);
	*stack_a = NULL;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (new == NULL)
			return (free_stack(stack_a), NULL);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (index_stack(stack_a), stack_a);
}

t_list	**stack_init_argc2(t_list **stack_a, int argc, char **argv)
{
	t_list	*new;
	int		i;

	i = 0;
	argv = ft_split(argv[1], ' ');
	if (!argv)
		return (NULL);
	if (ft_check_args(argc, argv, 0) == 1)
		return (print_error(), ft_free(argv), NULL);
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (stack_a == NULL)
		return (ft_free(argv), NULL);
	*stack_a = NULL;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (new == NULL)
			return (free_stack(stack_a), ft_free(argv), NULL);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (index_stack(stack_a), ft_free(argv), stack_a);
}

void	sort_stack(t_list **stack_a)
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
	print_stack(*stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;

	if (argc < 2)
		return (-1);
	if (argv[1][0] == '\0' || argv[1][0] == ' ')
		return (print_error(), -1);
	stack_a = NULL;
	if (argc == 2)
		stack_a = stack_init_argc2(stack_a, argc, argv);
	else
		stack_a = stack_init(stack_a, argc, argv);
	if (stack_a == NULL)
		return (-1);
	if (ft_isdupnode(*stack_a) == 1)
		return (print_error(), free_stack(stack_a), -1);
	sort_stack(stack_a);
	return (0);
}
