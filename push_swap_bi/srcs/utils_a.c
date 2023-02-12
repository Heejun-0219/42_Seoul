/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:21:29 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/04 08:35:36 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_pushswap *t, char alpha)
{
	t_node	*tmp;

	if (alpha == 'a')
	{
		tmp = del_node(t->b);
		push_node(t->a, tmp);
		write(1, "pa\n", 3);
	}
	else if (alpha == 'b')
	{
		tmp = del_node(t->a);
		push_node(t->b, tmp);
		write(1, "pb\n", 3);
	}
	return (1);
}

int	rotate(t_pushswap *t, char alpha)
{
	t_node	*tmp;

	if (alpha == 'a')
	{
		tmp = t->a->head;
		t->a->head = t->a->head->next;
		t->a->tail = tmp;
	}
	else if (alpha == 'b')
	{
		tmp = t->b->head;
		t->b->head = t->b->head->next;
		t->b->tail = tmp;
	}
	return (1);
}

int	reverse_rotate(t_pushswap *t, char alpha)
{
	t_node	*tmp;

	if (alpha == 'a')
	{
		tmp = t->a->tail;
		t->a->tail = t->a->tail->prev;
		t->a->head = tmp;
	}
	else if (alpha == 'b')
	{
		tmp = t->b->tail;
		t->b->tail = t->b->tail->prev;
		t->b->head = tmp;
	}
	return (1);
}

int	swap(t_pushswap *t, char alpha)
{
	t_node	*cur;

	if (alpha == 'a')
	{
		cur = t->a->head->next;
		t->a->head->next = cur->next;
		cur->next->prev = t->a->head;
		t->a->tail->next = cur;
		cur->prev = t->a->tail;
		cur->next = t->a->head;
		t->a->head->prev = cur;
		t->a->head = cur;
	}
	else if (alpha == 'b')
	{
		cur = t->b->head->next;
		t->b->head->next = cur->next;
		cur->next->prev = t->b->head;
		t->b->tail->next = cur;
		cur->prev = t->b->tail;
		cur->next = t->b->head;
		t->b->head->prev = cur;
		t->b->head = cur;
	}
	return (1);
}

void	reduce_factor(t_pushswap *t)
{
	t_node	*node;
	int		*array;

	array = get_array(t);
	get_index(t, array);
	while (t->a->size > 3)
	{
		node = t->a->head;
		if (node->data < t->mid)
			call_utils(t, "pb");
		else
			call_utils(t, "ra");
	}
	if (t->b->head->data < t->b->head->next->data)
		call_utils(t, "rb");
	free(array);
}
