/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:26:10 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 12:05:31 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_pushswap *t)
{
	t_node	*cur;
	int		i;
	int		flag;

	i = -1;
	flag = 1;
	cur = t->a->head;
	t->min = cur->data;
	t->max = cur->data;
	while (++i < t->a->size)
	{
		if (t->min > cur->data)
			t->min = cur->data;
		if (t->max < cur->data)
			t->max = cur->data;
		if (cur->data < cur->next->data)
			flag += 1;
		cur = cur->next;
	}
	return (flag);
}

void	delete_db(t_pushswap *t, int **db)
{
	int	i;

	i = -1;
	while (++i < t->db_height)
		free(db[i]);
	free(db);
}

void	reset_db(t_pushswap *t, int ***db)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->b->size)
	{
		j = -1;
		while (++j < 7)
			(*db)[i][j] = 0;
	}
	return ;
}

int	**database(t_pushswap *t)
{
	int	**array;
	int	i;

	t->db_height = t->b->size;
	array = (int **)malloc(sizeof(int *) * t->b->size);
	if (!array)
		error(0);
	i = -1;
	while (++i < t->b->size)
	{
		array[i] = (int *)malloc(sizeof(int) * 7);
		if (!array[i])
			error(0);
	}
	return (array);
}

int	ft_min(float a, float b)
{
	if (a < b)
		return ((int)a);
	return ((int)b);
}
