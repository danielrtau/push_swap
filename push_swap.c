/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:43:31 by danielro          #+#    #+#             */
/*   Updated: 2022/12/20 19:38:23 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(const int *stack, int n, int len)
{
	int i;

	i = 0;
	while (i <= len && n != *stack)
	{
		stack++;
		i++;
	}
	if (*stack == n)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		*a_stack;
	int		i;

	if (argc == 1)
		return (0);
	a_stack = ft_stack_alloc(argc, sizeof(int));
	i = 0;
	while (i < argc -1)
	{
		if(!ft_check_digit(argv[i + 1]))
		{
			write(1, "Error", 5);
			free(a_stack);
			return (0);
		}
		if (i > 0 && ft_check_duplicate(a_stack, ft_atoi(argv[i + 1]), argc - 2))
		{
			write(1, "Error", 5);
			free(a_stack);
			exit(1);
		}
		a_stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		printf("n%d:\t%d\n", i, a_stack[i]);
		i++;
	}
	free(a_stack);
	return (0);
}
/*
	while (i < argc)
	{
		if (ft_isnumber(argv[i]) == 0)
			return (ft_error());
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	if (ft_check_doubles(stack_a) == 0)
		return (ft_error());
	ft_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);

}
*/
