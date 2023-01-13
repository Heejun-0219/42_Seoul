/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:11:04 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/27 00:55:51 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;
	t_list	*p;
	int		*tmp;
	void	*new_content;

	p = NULL;
	start = lst;
	tmp = NULL;
	while (lst)
	{
		tmp = &lst->content;
		new_content = f((void *)tmp);
		new = ft_lstnew(*(int *)new_content);
		if (!new)
		{
			del(new_content);
			ft_lstclear(&p, del);
			return (NULL);
		}
		ft_lstadd_back(&p, new);
		lst = lst->next;
	}
	lst = start;
	return (p);
}
