/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:19:29 by danielro          #+#    #+#             */
/*   Updated: 2022/12/29 18:34:50 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dst, char *mv)
{
	t_stack	*aux;

	if (*src)
	{
		aux = (*src)->next;
		if(*dst)
			(*src)->next = *dst;
		else
			(*src)->next = NULL;
		*dst = *src;
		*src = aux;
		write(1, mv, 2);
		write(1, "\n", 1);
	}
}
