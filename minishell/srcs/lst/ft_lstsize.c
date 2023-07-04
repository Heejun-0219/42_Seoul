/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:50:21 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/13 20:59:51 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*start;
	int		size;

	size = 0;
	start = lst;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	lst = start;
	return (size);
}
