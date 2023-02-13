/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:15:57 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 12:43:05 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_pushswap *t, int *array)
{
	t_value	v;
	int		*arr;

	arr = array;
	v.a = -1;
	while (++v.a < t->a->size)
	{
		v.b = -1;
		while (++v.b < v.a)
		{
			if (arr[v.b] > arr[v.a])
			{
				v.c = arr[v.b];
				arr[v.b] = arr[v.a];
				arr[v.a] = v.c;
			}
			if (arr[v.b] == arr[v.a])
				remove_stack(2, t);
		}
	}
	t->mid = arr[(t->a->size - 1) / 2];
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	*get_array(t_pushswap *t)
{
	t_node	*cur;
	int		*array;
	int		i;

	array = (int *)malloc(sizeof(int) * (t->a->size));
	if (!array)
		remove_stack(0, t);
	i = 0;
	cur = t->a->head;
	while (cur != t->a->tail)
	{
		array[i] = cur->data;
		cur = cur->next;
		i++;
	}
	array[i] = cur->data;
	return (array);
}

static void	put_lis(t_pushswap *t, int *lis, int *array)
{
	t_node	*cur;
	int		i;
	int		max;

	i = 0;
	max = 0;
	cur = t->a->head;
	while (cur != t->a->tail)
	{
		cur->index = lis[i];
		cur = cur->next;
		if (max < ft_max(lis[i], lis[i + 1]))
			max = ft_max(lis[i], lis[i + 1]);
		i++;
	}
	cur->index = lis[i];
	get_index(t, array);
	t->lis = max;
}

int	get_lis(t_pushswap *t)
{
	int	*lis;
	int	*array;
	int	i;
	int	j;

	lis = (int *)malloc(sizeof(int) * (t->a->size));
	if (!lis)
		remove_stack(0, t);
	array = get_array(t);
	i = t->a->size - 1;
	lis[i] = 1;
	while (i >= 0)
	{
		j = i - 1;
		lis[i] = 1;
		while (j++ < t->a->size)
			if (array[i] < array[j])
				lis[i] = ft_max(lis[i], lis[j] + 1);
		--i;
	}
	put_lis(t, lis, array);
	free(array);
	free(lis);
	return (1);
}
