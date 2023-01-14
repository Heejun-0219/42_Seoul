/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operator_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:50:31 by heejunki          #+#    #+#             */
/*   Updated: 2023/01/14 14:58:07 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*pre_last;

	last = *a;
	pre_last = *a;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	last->next = *a;
	pre_last->next = NULL;
	*a = last;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*pre_last;

	last = *b;
	pre_last = *b;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	last->next = *b;
	pre_last->next = NULL;
	*b = last;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	t_list	*last;
	t_list	*pre_last;

	last = *a;
	pre_last = *a;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	last->next = *a;
	pre_last->next = NULL;
	*a = last;
	last = *b;
	pre_last = *b;
	while (last->next != NULL)
	{
		pre_last = last;
		last = last->next;
	}
	last->next = *b;
	pre_last->next = NULL;
	*b = last;
	ft_putstr_fd("rrr\n", 1);
}
