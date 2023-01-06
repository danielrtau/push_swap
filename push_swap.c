/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:43:31 by danielro          #+#    #+#             */
/*   Updated: 2023/01/06 17:48:08 by danielro         ###   ########.fr       */
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
	int		min[3];
	int		rotate;

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
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc - 1)
	{
		aux = ft_new_stack(input[i]);
		ft_stack_add(&stack_a, aux);
		i++;
	}
	free(input);

//Algorithm
	if (ft_is_solved(stack_a))
	{
		free(aux);
		free(stack_a);
		free(stack_b);
		exit(0);
	}
//		ft_finish(aux);
	ft_check_if_swap(stack_a);
	if(ft_check_if_solved(stack_a, stack_b))
		ft_finish(aux);
	min[0] = ft_stack_size(stack_a);
	min[1] = ft_stack_min(stack_a);
	min[2] = ft_stack_pos(stack_a, min[1]);
	while (1)
	{
		while(1)
		{
			if (min[2] == 1)
			{
				ft_push(&stack_a, &stack_b, "pb");
				ft_check_if_swap(stack_a);
				if(ft_check_if_solved(stack_a, stack_b))
					ft_finish(aux);
				break;
			}
			else
			{
				if (min[2] <= min[0] / 2)
				{
					rotate = min[2] - 2;
					while (rotate--)
					{
						ft_rotate(&stack_a, "ra");
						ft_check_if_swap(stack_a);
					}
				}
				else
				{
					rotate = min[0] - min[2] + 1;
					while (rotate--)
					{
						ft_reverse_rotate(&stack_a, "rra");
						ft_check_if_swap(stack_a);
					}
				}
				if (ft_check_if_solved(stack_a, stack_b))
					ft_finish(aux);
				min[2] = 1;
			}
		}
		min[0] = ft_stack_size(stack_a);
		min[1] = ft_stack_min(stack_a);
		min[2] = ft_stack_pos(stack_a, min[1]);
	}
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
