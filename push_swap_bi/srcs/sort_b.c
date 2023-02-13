/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:24:19 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 12:05:30 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_a(t_pushswap *t)
{
	t_node	*cur;
	t_value	v;

	v.a = 2147483647;
	v.b = -2147483648;
	v.c = -1;
	while (t->a->size > 3)
		reduce_factor(t);
	cur = t->a->head;
	while (++v.c < t->a->size)
	{
		v.a = ft_min((float)cur->data, (float)v.a);
		v.b = ft_max(cur->data, v.b);
		cur = cur->next;
	}
	if ((cur->data == v.b && t->a->size == 3) || \
		(t->a->size == 2 && cur->data == v.b))
		call_utils(t, "ra");
	if (cur->next->data == v.b && t->a->size == 3)
		call_utils(t, "rra");
	if (v.a == t->a->head->next->data && t->a->size == 3)
		call_utils(t, "sa");
	while (t->b->size > 0)
		call_utils(t, "pa");
}

void	a_to_b(t_pushswap *t)
{
	int	size;
	int	i;

	size = t->a->size;
	i = -1;
	while (++i < size)
	{
		if (t->a->head->index != t->lis)
		{
			call_utils(t, "pb");
			if (size > 100 && t->b->head->data >= t->mid)
				call_utils(t, "rb");
		}
		else
		{
			call_utils(t, "ra");
			t->lis--;
		}
	}
}

void	last_sort(t_pushswap *t)
{
	t_node	*cur;
	int		i;

	cur = t->a->head;
	i = -1;
	while (++i < t->a->size)
	{
		if (t->min == cur->data)
			break ;
		cur = cur->next;
	}
	if (i < t->a->size - i)
		while (--i >= 0)
			call_utils(t, "ra");
	else
		while (t->a->size - (++i) >= 0)
			call_utils(t, "rra");
}

static void	set_push(t_pushswap *t, int ***db, int this)
{
	while ((*db)[this][0]-- > 0)
		call_utils(t, "ra");
	while ((*db)[this][1]-- > 0)
		call_utils(t, "rra");
	while ((*db)[this][2]-- > 0)
		call_utils(t, "rb");
	while ((*db)[this][3]-- > 0)
		call_utils(t, "rrb");
	while ((*db)[this][4]-- > 0)
		call_utils(t, "rr");
	while ((*db)[this][5]-- > 0)
		call_utils(t, "rrr");
	call_utils(t, "pa");
}

void	get_push(t_pushswap *t, int ***db)
{
	int	i;
	int	min;
	int	push_this;

	i = 0;
	min = (*db)[i][6];
	while (++i < t->b->size)
		if (min > (*db)[i][6])
			min = (*db)[i][6];
	i = -1;
	while (++i < t->b->size)
		if (min == (*db)[i][6])
			push_this = i;
	i = -1;
	set_push(t, db, push_this);
}
