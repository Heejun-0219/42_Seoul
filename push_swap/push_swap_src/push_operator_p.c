/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operator_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:51:54 by heejunki          #+#    #+#             */
/*   Updated: 2023/01/14 14:56:09 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_putstr_fd("pb\n", 1);
}
