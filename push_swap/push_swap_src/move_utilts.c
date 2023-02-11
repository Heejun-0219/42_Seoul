/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utilts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:04:24 by heejunki          #+#    #+#             */
/*   Updated: 2023/02/11 10:05:08 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_val(int *max_or_min_pos, int a_size, int content)
{
	if (content > max_or_min_pos[0])
		return (max_or_min_pos[2]);
	if (content < max_or_min_pos[1])
		return (max_or_min_pos[3]);
	return (a_size + 1);
}

int	max_val(int distance, int sector)
{
	if (distance < 0)
	{
		distance *= -1;
		sector *= -1;
	}
	if (distance > sector)
		return (distance);
	return (sector);
}

int	mix_val(int distance, int sector)
{
	if (distance > 0)
		return (distance - sector);
	return (sector - distance);
}

int	max_or_min(t_list *a, int a_size, int content)
{
	int	max_or_min_pos[5];

	max_or_min_pos[0] = a->content;
	max_or_min_pos[1] = a->content;
	max_or_min_pos[2] = 0;
	max_or_min_pos[3] = 0;
	max_or_min_pos[4] = 0;
	while (a != NULL)
	{
		if (a->content >= max_or_min_pos[0])
		{
			max_or_min_pos[0] = a->content;
			max_or_min_pos[2] = max_or_min_pos[4] + 1;
		}
		if (a->content < max_or_min_pos[1])
		{
			max_or_min_pos[1] = a->content;
			max_or_min_pos[3] = max_or_min_pos[4];
		}
		a = a->next;
		max_or_min_pos[4]++;
	}
	return (return_val(max_or_min_pos, a_size, content));
}

int	find_sector(t_list *a, int a_size, int content)
{
	const t_list	*last = ft_lstlast(a);
	int				i;

	i = max_or_min(a, a_size, content);
	if (i != a_size + 1)
		return (find_distance(i, a_size));
	if (content < a->content && content > last->content)
		return (0);
	i = 1;
	while (!(content > a->content && content < (a->next)->content))
	{
		a = a->next;
		i++;
	}
	return (find_distance(i, a_size));
}
