/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:38:23 by danielro          #+#    #+#             */
/*   Updated: 2022/12/21 20:42:04 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add(t_stack **lst, t_stack *new)
{
	t_stack	*a;

	if (*lst)
	{
		a = ft_stack_last(*lst);
		a->next = new;
	}
	else
		*lst = new;
}
