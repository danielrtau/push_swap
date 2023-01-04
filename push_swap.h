/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:29:45 by danielro          #+#    #+#             */
/*   Updated: 2023/01/04 20:55:29 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
void	*ft_stack_alloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

typedef struct n_stack
{
	int				number;
	struct n_stack	*next;
}					t_stack;

void	ft_stack_add(t_stack **lst, t_stack *new);
t_stack	*ft_new_stack(int number);
t_stack	*ft_stack_last(t_stack *lst);
void	ft_swap(t_stack *stack, char *mv);
void	ft_push(t_stack **src, t_stack **dst, char *mv);
void	ft_rotate(t_stack **stack, char *mv);
void	ft_reverse_rotate(t_stack **stack, char *mv);
int		ft_stack_size(t_stack *stack);
int		ft_is_solved(t_stack *stack);
void	ft_check_if_solved(t_stack *stack_a, t_stack *stack_b);
void	ft_check_if_swap(t_stack *stack_a, t_stack *stack_b, int opt);
int		ft_stack_pos(t_stack *stack, int min);
int		ft_stack_min(t_stack *stack);

# endif
