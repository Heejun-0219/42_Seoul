/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:28:49 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 12:05:29 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_b(int *db, t_value *v)
{
	if (v->min == v->b)
	{
		db[5] = ft_min((float)db[1], (float)db[3]);
		db[3] -= db[5];
		db[1] -= db[5];
		db[0] = 0;
		db[2] = 0;
	}
	else if (v->min == v->c)
	{
		db[1] = 0;
		db[2] = 0;
	}
	else if (v->min == v->d)
	{
		db[0] = 0;
		db[3] = 0;
	}
}

static void	calculate_a(int *db)
{
	t_value	*v;

	v = (t_value *)malloc(sizeof(t_value));
	v->a = db[0] + db[2] - ft_min((float)db[0], (float)db[2]);
	v->b = db[1] + db[3] - ft_min((float)db[1], (float)db[3]);
	v->c = db[0] + db[3];
	v->d = db[1] + db[2];
	v->min = ft_min(ft_min(ft_min((float)v->a, (float)v->b), (float)v->c), \
	(float)v->d);
	if (v->min == v->a)
	{
		db[4] = ft_min((float)db[0], (float)db[2]);
		db[2] -= db[4];
		db[0] -= db[4];
		db[1] = 0;
		db[3] = 0;
	}
	else
		calculate_b(db, v);
	db[6] = db[0] + db[1] + db[2] + db[3] + db[4] + db[5];
	free(v);
}

static void	dest_me(t_pushswap *t, int ***db, t_node *me, int my_location)
{
	t_node	*com;
	t_value	v;

	com = t->a->head;
	v.a = -1;
	v.b = 0;
	v.min = 2147483647;
	v.c = -2147483648;
	while (++v.a < t->a->size)
	{
		v.min = ft_min((float)com->data, (float)v.min);
		v.c = ft_max(com->data, v.c);
		com = com->next;
	}
	v.a = -1;
	while (++v.a < t->a->size - 1)
	{
		if ((com->data < me->data && com->next->data > me->data) || \
		(com->data < me->data && com->next->data == v.min) || \
		(com->data == v.c && com->next->data > me->data))
			v.b = v.a + 1;
		com = com->next;
	}
	(*db)[my_location][0] = v.b;
	(*db)[my_location][1] = t->a->size - v.b;
}

static void	find_me(t_pushswap *t, int ***db)
{
	t_node	*me;
	int		my_location;

	me = t->b->head;
	my_location = -1;
	while (++my_location < t->b->size)
	{
		(*db)[my_location][2] = my_location;
		(*db)[my_location][3] = t->b->size - my_location;
		dest_me(t, db, me, my_location);
		calculate_a((*db)[my_location]);
		me = me->next;
	}
	return ;
}

void	b_to_a(t_pushswap *t)
{
	int	**db;

	db = database(t);
	while (t->b->size)
	{
		reset_db(t, &db);
		find_me(t, &db);
		get_push(t, &db);
	}
	last_sort(t);
	delete_db(t, db);
}
