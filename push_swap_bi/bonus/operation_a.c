/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:08:21 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/04 08:33:15 by jaewpark         ###   ########.fr       */
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
	}
	else if (alpha == 'b')
	{
		tmp = del_node(t->a);
		push_node(t->b, tmp);
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

void	call_utils(t_pushswap *t, char *alpha)
{
	if (ft_strcmp(alpha, "sa") == 0)
		swap(t, 'a');
	if (ft_strcmp(alpha, "sb") == 0)
		swap(t, 'b');
	if (ft_strcmp(alpha, "ra") == 0)
		rotate(t, 'a');
	if (ft_strcmp(alpha, "rb") == 0)
		rotate(t, 'b');
	if (ft_strcmp(alpha, "rra") == 0)
		reverse_rotate(t, 'a');
	if (ft_strcmp(alpha, "rrb") == 0)
		reverse_rotate(t, 'b');
	if (ft_strcmp(alpha, "ss") == 0)
		ss(t);
	if (ft_strcmp(alpha, "rr") == 0)
		rr(t);
	if (ft_strcmp(alpha, "rrr") == 0)
		rrr(t);
	if (ft_strcmp(alpha, "pa") == 0)
		push(t, 'a');
	if (ft_strcmp(alpha, "pb") == 0)
		push(t, 'b');
}
