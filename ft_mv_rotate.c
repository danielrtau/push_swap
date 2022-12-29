/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:50:25 by danielro          #+#    #+#             */
/*   Updated: 2022/12/29 18:53:24 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack, char *mv)
{
	t_stack	*aux;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	aux = *stack;
	last = ft_stack_last(*stack);
	*stack = (*stack)->next;
	last->next = aux;
	aux->next = NULL;
	write(1, mv, 2);
	write(1, "\n", 1);
}
