/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:44:54 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/25 23:38:12 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstdel_node(t_list *list, t_node *node)
{
	if (list == NULL || node == NULL)
		return (ft_error("argument has been wrong", FAILURE));
	if (node->next_node == NULL && node->prev_node == NULL)
	{
		free(node->content);
		free(node);
		*list = ft_list_init();
		return (SUCCESS);
	}
	if (list->front_node == node)
		ft_del_front_node(list, node);
	else if (list->back_node == node)
		ft_del_back_node(list, node);
	else if (list->cur_node == node)
		ft_del_cur_node(list, node);
	else
		ft_del_node(node);
	return (SUCCESS);
}
