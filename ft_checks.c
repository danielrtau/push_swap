/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:31:16 by danielro          #+#    #+#             */
/*   Updated: 2023/01/04 20:55:34 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_if_swap(t_stack *stack_a, t_stack *stack_b, int opt)
{
	if (stack_a->number > stack_a->next->number)
	{
		ft_swap(stack_a, "sa");
		if (opt == 1)
			ft_check_if_solved(stack_a, stack_b);
	}
	return ;
}

int	ft_is_solved(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux->next)
	{
		if (aux->number > aux->next->number)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	ft_check_if_solved(t_stack *stack_a, t_stack *stack_b)
{
	int		count;

	if (ft_is_solved(stack_a))
	{
		if (stack_b)
		{
			count = ft_stack_size(stack_b);
			while (count--)
				ft_push(&stack_b, &stack_a, "pa");
		}
		printf("SOLVED!");
		exit (0);
	}
	return ;
}
