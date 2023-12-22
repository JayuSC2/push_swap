/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:39:17 by julian            #+#    #+#             */
/*   Updated: 2023/12/22 18:39:52 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void   print_error(void)
{
    ft_putendl_fd("Error", 2);
    exit(1);
}

static void   check_duplicates(t_stack *stack)
{
    t_stack *tmp;
    t_stack *tmp2;

    tmp = stack;
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (tmp->value == tmp2->value)
                print_error();
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}
