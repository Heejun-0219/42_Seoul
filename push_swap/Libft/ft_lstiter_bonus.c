/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:01:41 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/13 20:52:34 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*start;
	int		*tmp;

	start = lst;
	tmp = NULL;
	while (lst)
	{
		tmp = &lst->content;
		f((void *)tmp);
		lst = lst->next;
	}
	lst = start;
}
