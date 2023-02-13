/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:45 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 14:12:26 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	list_print(t_list *ls)
{
	t_node	*cur;

	cur = ls->head;
	while (ls->size)
	{
		printf("%d ",cur->data);
		cur = cur->next;
		ls->size--;
	}
}

int	main(int argc, char **argv)
{
	t_pushswap	*t;

	if (argc < 2)
		exit(1);
	t = (t_pushswap *)malloc(sizeof(t_pushswap));
	init_pushswap(t);
	if (!t || !t->a || !t->b)
		remove_stack(0, t);
	if (!parsing_arg(argv, argc, t))
		remove_stack(1, t);
	if (t->a->size <= 5)
		short_a(t);
	if (t->a->size > 5)
	{
		get_lis(t);
		a_to_b(t);
		b_to_a(t);
	}
	list_print(t->a);
	reset_list(t->a);
	reset_list(t->b);
	free(t);
	return (0);
}
