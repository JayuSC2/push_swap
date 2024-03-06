/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juitz <juitz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:01:22 by juitz             #+#    #+#             */
/*   Updated: 2024/03/06 16:12:12 by juitz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isdigit(int input)
{
	if (input >= 48 && input <= 57)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf ("%d", ft_isdigit('3'));
	printf ("%d", ft_isdigit('z'));
}
*/