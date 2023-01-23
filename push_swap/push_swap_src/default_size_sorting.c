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

void	rotate_to_start(t_list **a, int a_size)
{
	int	i;
	int start;
	int	pos;
	t_list *tmp;

	i = 0;
	pos = 0;
	tmp = *a;
	start = tmp->content;
	while (i < a_size)
	{	
		if (start > tmp->content)
		{
			start = tmp->content;
			pos = i;
		} 
		tmp = tmp->next;
		i++;
	}
	tmp = NULL;
	pos = find_distance(pos, a_size);
	ra_rra_move_to_a(0, pos, a, &tmp);
}

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

void	five_size_sorting(t_list **a, t_list **b)
{
	int	i;

	i = 2;
	while (i-- > 0)
		pb(a, b);
	three_size_sorting(a);
	move_to_a(a, b);
	rotate_to_start(a, ft_lstsize(*a));	
}
