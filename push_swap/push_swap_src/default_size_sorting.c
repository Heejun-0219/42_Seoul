/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_size_sorting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:22:24 by heejunki          #+#    #+#             */
/*   Updated: 2023/01/19 01:33:05 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_size_sorting(t_list **a)
{
	int		i;
	int		j;
	int		x;
	t_list	*tmp;

	tmp = NULL;
	i = 0;
	j = 0;
	x = 0;
	while (!(i < j && j < x && x > i))
	{
		tmp = *a;
		i = tmp->content;
		tmp = tmp->next;
		j = tmp->content;
		tmp = tmp->next;
		x = tmp->content;
		if ((i > j && j < x && x > i) || (i > j && j > x && x < i)
			|| (i < j && j > x && x > i))
			sa(a);
		if (i > j && j < x && x < i)
			ra(a);
		if (i < j && j > x && x < i)
			rra(a);
	}
}

void	five_size_sorting(t_list **a)
{
	
}
