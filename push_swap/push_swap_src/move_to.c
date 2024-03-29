/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 09:36:27 by heejunki          #+#    #+#             */
/*   Updated: 2023/02/11 10:07:59 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_to_b(t_list *a, int *lis, int max)
{
	int	pos;
	int	i;
	int	flag;

	pos = 0;
	i = 0;
	while (a != NULL)
	{
		i = 0;
		flag = 0;
		while (i < max)
		{
			if (a->content == lis[i])
				flag = 1;
			i++;
		}
		if (!flag)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}

int	mid_val(int size, t_list *b)
{
	int		i;

	if (size < 2)
		return (INT_MAX);
	i = 0;
	while (i < size / 2 - 1)
	{
		b = b->next;
	}
	return (b->content);
}

void	move_to_b(t_list **a, t_list **b, int *lis, int max)
{
	int	a_size;
	int	count_mov;

	a_size = ft_lstsize(*a);
	while (a_size > max)
	{
		count_mov = pos_to_b(*a, lis, max);
		if (count_mov == -1)
			return ;
		while (count_mov-- > 0)
			ra(a);
		pb(a, b);
		a_size = ft_lstsize(*a);
	}
}

int	find_best_pos_move(int *distance, int *sector, int b_size)
{
	int	*tmp;
	int	i;
	int	pos;

	tmp = (int *)malloc(sizeof(int) * b_size);
	if (!tmp)
		return (-1);
	i = 0;
	pos = 0;
	while (i < b_size)
	{
		/*if ((distance[i] > 0 && sector[i] > 0)
			|| (distance[i] < 0 && sector[i] < 0))
			tmp[i] = max_val(distance[i], sector[i]);
		else
		{
			tmp[i] = mix_val(distance[i], sector[i]);
		}*/
		tmp[i] = max_val(distance[i], sector[i]);
		if (tmp[i] < tmp[pos])
			pos = i;
		i++;
	}
	free(tmp);
	return (pos);
}

int	pos_to_a(t_list **a, int a_size, t_list **b, int b_size)
{
	int		*b_data_distance;
	int		*b_data_sector;
	t_list	*tmp;
	int		i;

	b_data_distance = (int *)malloc(sizeof(int) * b_size);
	b_data_sector = (int *)malloc(sizeof(int) * b_size);
	if (!b_data_distance || !b_data_sector)
	{
		list_free(a);
		list_free(b);
		exit(-1);
	}
	i = 0;
	tmp = *b;
	while (i < b_size)
	{
		b_data_distance[i] = find_distance(i, b_size);
		b_data_sector[i] = find_sector(*a, a_size, tmp->content);
		tmp = tmp->next;
		i++;
	}
	i = find_best_pos_move(b_data_distance, b_data_sector, b_size);
	if (i == -1)
	{
		list_free(a);
		list_free(b);
	}
	i = ra_rra_move_to_a(b_data_distance[i], b_data_sector[i], a, b);
	free(b_data_distance);
	free(b_data_sector);
	return (i);
}

void	move_to_a(t_list **a, t_list **b)
{
	int	count_mov;
	int	a_size;
	int	b_size;

	a_size = ft_lstsize(*a);
	b_size = ft_lstsize(*b);
	while (*b != NULL)
	{
		count_mov = pos_to_a(a, a_size, b, b_size);
		while (count_mov > 0)
		{
			rb(b);
			count_mov--;
		}
		while (count_mov < 0)
		{
			rrb(b);
			count_mov++;
		}
		pa(a, b);
		a_size++;
		b_size--;
	}
}
