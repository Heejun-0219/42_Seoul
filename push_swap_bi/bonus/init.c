/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:51:40 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/02 14:23:29 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(t_list *ls)
{
	ls->head = NULL;
	ls->tail = NULL;
	ls->size = 0;
	ls->flag = 0;
}

void	init_pushswap(t_pushswap *t)
{
	t->a = (t_list *)malloc(sizeof(t_list));
	t->b = (t_list *)malloc(sizeof(t_list));
	init_list(t->a);
	init_list(t->b);
}

int	is_sort(t_pushswap *t, int size)
{
	t_node	*cur;
	int		index;

	cur = t->a->head;
	index = 0;
	if (t->a->size != size)
		return (0);
	while (++index < t->a->size)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	error(int code)
{
	if (code == 0)
		write(1, "There was a problem while malloc creating\n", 42);
	else if (code == 1)
		write(1, "There was a problem while parsing\n", 35);
	write(1, "Error\n", 6);
	exit(1);
}
