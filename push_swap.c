/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:43:31 by danielro          #+#    #+#             */
/*   Updated: 2022/12/21 21:30:24 by danielro         ###   ########.fr       */
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
	int		*input;
	t_stack	*stack_a;
//	t_stack	*stack_b;
	t_stack	*aux;
	int		i;

	if (argc == 1)
		return (0);
	input = ft_stack_alloc(argc, sizeof(int));
	i = 0;
	while (i < argc - 1)
	{
		if(!ft_check_digit(argv[i + 1]))
		{
			write(1, "Error", 5);
			free(input);
			return (0);
		}
		if (i > 0 && ft_check_duplicate(input, ft_atoi(argv[i + 1]), argc - 2))
		{
			write(1, "Error", 5);
			free(input);
			exit(1);
		}
		input[i] = ft_atoi(argv[i + 1]);
		i++;
	}
/*
	i = 0;
	while (i < argc - 1)
	{
		printf("n%d:\t%d\n", i, input[i]);
		i++;
	}
*/
	i = 0;
	stack_a = ft_new_stack(input[i]);
	i++;
	while (i < argc - 1)
	{
		aux = ft_new_stack(input[i]);
		ft_stack_add(&stack_a, aux);
		i++;
	}
	free(input);
	i = 0;
	while (i < argc - 1)
	{
		printf("n%d:\t%d\n", i, stack_a->number);
		stack_a = stack_a->next;
		i++;
	}
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
