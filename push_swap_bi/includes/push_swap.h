/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:04:23 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 12:42:01 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "list.h"
# include <unistd.h>

typedef struct s_stack
{
	int		*stack;
	int		top;
}				t_stack;

typedef struct s_value
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	min;
}	t_value;

typedef struct s_pushswap
{
	t_list	*a;
	t_list	*b;
	int		min;
	int		mid;
	int		max;
	int		lis;
	int		db_height;
}	t_pushswap;

void	reduce_factor(t_pushswap *t);
int		swap(t_pushswap *t, char alpha);
int		rotate(t_pushswap *t, char alpha);
int		reverse_rotate(t_pushswap *t, char alpha);
int		push(t_pushswap *t, char alpha);

void	call_utils(t_pushswap *t, char *alpha);
void	ss(t_pushswap *t);
void	rr(t_pushswap *t);
void	rrr(t_pushswap *t);
int		ft_strcmp(char *a, char *b);

int		parsing_arg(char **argv, int argc, t_pushswap *t);

void	get_index(t_pushswap *t, int *array);
int		*get_array(t_pushswap *t);
int		get_lis(t_pushswap *t);
int		ft_max(int a, int b);

void	a_to_b(t_pushswap *t);
void	b_to_a(t_pushswap *t);
void	get_push(t_pushswap *t, int ***db);
void	last_sort(t_pushswap *t);
void	short_a(t_pushswap *t);

void	reset_db(t_pushswap *t, int ***db);
void	delete_db(t_pushswap *t, int **db);
int		ft_min(float a, float b);
int		**database(t_pushswap *t);
int		check_sort(t_pushswap *t);

void	init_pushswap(t_pushswap *t);
void	init_list(t_list *ls);
void	error(int code);
int		is_sort(t_pushswap *t, int size);
void	remove_stack(int sign, t_pushswap *t);

#endif
