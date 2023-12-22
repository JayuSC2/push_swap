/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:08:49 by julian            #+#    #+#             */
/*   Updated: 2023/12/22 18:36:31 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void   print_error(void)
{
    ft_putendl_fd("Error", 2);
    exit(1);
}

long	ft_atol(const char *str)
{
	int	i;
	long    num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

int	ft_isspace(int input)
{
	if (input == ' ' || input == '\t' || input == '\n' || input == '\v' || input == '\f' || input == '\r')
		return (1);
	return (0);
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