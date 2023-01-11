/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:29:30 by danielro          #+#    #+#             */
/*   Updated: 2023/01/10 22:59:20 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_list(char *argv)
{
	char	*aux;

	aux = argv;
	while (*aux)
	{
		if (*aux == ' ')
			return (1);
		aux++;
	}
	return (0);
}

int	ft_count_num(char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		while (argv[i] == ' ' && argv[i])
			i++;
		if (argv[i])
			count++;
		else
			break;
		while (argv[i] != ' ' && argv[i])
			i++;
	}
	return (count);
}

int	ft_total_num(char **argv, int argc)
{
	int	i;
	int n;

	i = 1;
	n = 0;
	while (i < argc)
	{
		if (ft_is_list(argv[i]))
			n += ft_count_num(argv[i]);
		else
			n++;
		i++;
	}
	return (n);
}

char	*ft_next_num(char *argv)
{
	char	*aux;

	aux = argv;
	while (*aux == ' ' && *aux)
		aux++;
	while (*aux != ' ' && *aux)
		aux++;
	while (*aux == ' ' && *aux)
		aux++;
	return (aux);
}
