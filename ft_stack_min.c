/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:36:06 by danielro          #+#    #+#             */
/*   Updated: 2023/01/04 20:40:43 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_min(t_stack *stack)
{
	int	min;

	min = stack->number;
	while (stack)
	{
		if (stack->number < min)
			min = stack->number;
		stack = stack->next;
	}
	return (min);
}

int	ft_stack_pos(t_stack *stack, int min)
{
	int	pos;

	pos = 1;
	while (stack)
	{
		if (stack->number == min)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}
