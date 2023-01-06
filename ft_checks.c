/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:31:16 by danielro          #+#    #+#             */
/*   Updated: 2023/01/06 17:27:40 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_if_swap(t_stack *stack)
{
	if (stack->number > stack->next->number)
		ft_swap(stack, "sa");
	return ;
}

void	ft_finish(t_stack *stack)
{
	free(stack);
	exit(0);
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

int	ft_check_if_solved(t_stack *stack_a, t_stack *stack_b)
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
		return(1);
	}
	return (0);
}
