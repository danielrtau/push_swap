/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:43:31 by danielro          #+#    #+#             */
/*   Updated: 2023/01/04 18:15:51 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack);

char	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
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
	t_stack	*stack_b;
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
	i = 0;
	stack_a = ft_new_stack(input[i]);
	stack_b = NULL;
	i++;
	while (i < argc - 1)
	{
		aux = ft_new_stack(input[i]);
		ft_stack_add(&stack_a, aux);
		i++;
	}
	free(input);
//Algorithm
	if (ft_check_if_solved(&stack_a))
		finish();
	if (ft_check_if_swap(&stack_a))
	{
		ft_swap(&stack_a,"sa");
		ft_check_if_solved(&stack_a);
	}
	while (1)
	{
		ft_find_min();
	}
	ft_print_stack(stack_a);

	free(aux);
	return (0);
}

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	printf("--------------------------------\n");
	while (stack && stack->next != NULL)
	{
		printf("n%d:\t%d\n", i, stack->number);
		stack = stack->next;
		i++;
	}
	if (stack)
		printf("n%d:\t%d\n", i, stack->number);
}
/*
   1.	check if solved
	finish
		stack b?
			count stack b
			push a #b
		solved!
	return
2.	swap a?
		swap
		1.
	return
3.	find min
4.	min first?
		push b
		2.
		3.
	relocate min (#/2 - find pos)
	# times locates min *if ra (-2 because swap) *if rra (+1)
		ra - rra
		2. (no check 1.)
	1.
	min first
	4.
*/
