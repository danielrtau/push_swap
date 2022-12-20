/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:47:52 by danielro          #+#    #+#             */
/*   Updated: 2022/12/20 19:28:05 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_stack_alloc(size_t count, size_t size)
{
	unsigned int	a;
	void			*b;

	a = count * size;
	b = malloc(a);
	if (b == NULL)
		return (NULL);
	ft_memset(b, '.', a);
	return (b);
}
