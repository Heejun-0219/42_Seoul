/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_check_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:08:30 by heejunki          #+#    #+#             */
/*   Updated: 2023/01/19 00:49:00 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_order(t_list **stack)
{
	t_list	*tmp;
	t_list	*ttmp;

	tmp = *stack;
	ttmp = tmp->next;
	while (ttmp != NULL)
	{
		if (tmp->content > ttmp->content)
			return ;
		tmp = tmp->next;
		ttmp = ttmp->next;
	}
	exit(0);
}

void	ft_lst_inverted(t_list **stack)
{
	t_list	*tmp;
	t_list	*ttmp;

	tmp = *stack;
	ttmp = tmp->next;
	while (ttmp != NULL)
	{
		if (tmp->content < ttmp->content)
			return ;
		tmp = tmp->next;
		ttmp = ttmp->next;
	}
	sa(stack);
}
