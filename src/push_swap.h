/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:35 by juitz             #+#    #+#             */
/*   Updated: 2024/01/22 12:44:38 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:57:01 by julian            #+#    #+#             */
/*   Updated: 2023/12/21 19:22:20 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_list
{
    int				value;
    int				index;
    struct s_list  *next;
}					t_list;

void ft_swap(int *a, int *b);
int swap(t_list **stack);
int sa(t_list **stack_a);
int sb(t_list **stack_b);
int   push(t_list **stack1, t_list **stack2);
int pa(t_list **stack_a, t_list **stack_b);
int pb(t_list **stack_b, t_list **stack_a);
int   rotate(t_list **stack);
int ra(t_list **stack_a);
int rb(t_list **stack_b);
void   rr(t_list **stack);
int rra(t_list **stack_a);
int rrb(t_list **stack_b);

void    ft_check_args(int argc, char **argv);
int		ft_isdigit(int c);
int		ft_isnumber(char *str);
int		is_sorted(t_list **stack);
void	ft_free(char **str);
void	free_stack(t_list **stack);
long	ft_atol(const char *str);
void    check_duplicates(int argc, char **argv);
void	check_minmax(t_list *stack);
void    print_stack(t_list *stack);
void    print_error(void);

void	index_stack(t_list **stack);
//static t_list	*get_next_min(t_list **stack);

void    radix_sort(t_list **stack_a, t_list **stack_b);
void    smol_sort(t_list **stack_a, t_list **stack_b);
//static int		get_max_bits(t_list *stack);

t_list *ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **stack, t_list *tmp);
int     ft_lstsize(t_list *lst);

#endif