/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:33:44 by danielro          #+#    #+#             */
/*   Updated: 2022/12/23 13:05:39 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char *mv)
{
	int	aux;

	if (stack->next)
	{
		aux = stack->number;
		stack->number = stack->next->number;
		stack->next->number = aux;
		write(1, mv, 2);
		write(1, "\n", 1);
	}
}
