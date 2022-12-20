/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:29:45 by danielro          #+#    #+#             */
/*   Updated: 2022/12/20 18:12:19 by danielro         ###   ########.fr       */
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
	int				data;
	struct s_stack	*next;
}					t_stack;

# endif
