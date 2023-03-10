/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:43:31 by danielro          #+#    #+#             */
/*   Updated: 2023/01/11 12:21:36 by danielro         ###   ########.fr       */
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
		if (str[i] == 32 && i > 0)
			i++;
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
	if (len == 0)
		return (0);
	while (i < len && n != *stack)
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
	int		total_numbers;
	int		n_list;
	char	*arg_lst;

	if (argc == 1)
		return (0);
	i = 0;
	while (i < argc - 1)
	{
		if(!ft_check_digit(argv[i + 1]))
		{
			write(2, "Error", 5);
			return (0);
		}
		i++;
	}
	i = 1;
	total_numbers = ft_total_num(argv, argc);
	input = ft_stack_alloc(total_numbers, sizeof(int));
	total_numbers = 0;
	while (i < argc)
	{
		if (ft_is_list(argv[i]))
		{
			arg_lst = argv[i];
			n_list = ft_count_num(arg_lst);
			while (n_list--)
			{
				if (ft_check_duplicate(input, ft_atoi(arg_lst), total_numbers))
				{
					write(2, "Error", 5);
					free(input);
					return (0);
				}
				input[total_numbers] = ft_atoi(arg_lst);
				arg_lst = ft_next_num(arg_lst);
				total_numbers++;
			}
		}
		else
		{
			if (ft_check_duplicate(input, ft_atoi(argv[i]), total_numbers))
			{
				write(2, "Error", 5);
				free(input);
				return (0);
			}
			input[total_numbers] = ft_atoi(argv[i]);
			total_numbers++;
		}
		i++;
	}
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (i < total_numbers)
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
