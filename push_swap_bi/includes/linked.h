/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:04:20 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 12:17:04 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_H
# define LINKED_H

# include <stdlib.h>

typedef struct s_node
{
	int				index;
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
	int		flag;
}	t_list;

t_node	*del_node(t_list *ls);
void	push_node(t_list *ls, t_node *newNode);
void	add_node(t_list *ls, int data);
void	reset_list(t_list *ls);
int		search_node(t_list *ls, int search);

#endif
