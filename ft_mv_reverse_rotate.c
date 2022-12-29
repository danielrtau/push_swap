/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:57:22 by danielro          #+#    #+#             */
/*   Updated: 2022/12/29 18:58:23 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack, char *mv)
{
	t_stack	*aux;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	aux = *stack;
	last = ft_stack_last(*stack);
	while (aux->next != last)
		aux = aux->next;
	aux->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, mv, 3);
	write(1, "\n", 1);
}
