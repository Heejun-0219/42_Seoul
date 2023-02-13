/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:07:31 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 12:43:46 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_node(t_list *ls, t_node *newNode)
{
	if (ls->head == NULL)
	{
		ls->head = newNode;
		ls->tail = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else
	{
		newNode->next = ls->head;
		newNode->prev = ls->head->prev;
		ls->head->prev->next = newNode;
		ls->head->prev = newNode;
		ls->head = newNode;
	}
	ls->size++;
}

int	search_node(t_list *ls, int search)
{
	t_node	*cur;

	cur = ls->head;
	while (cur != ls->tail)
	{
		if (cur->data == search)
			break ;
		cur = cur->next;
	}
	return (cur->index);
}

void	add_node(t_list *ls, int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->data = data;
	tmp->index = 0;
	if (ls->head == NULL)
	{
		ls->head = tmp;
		ls->tail = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->prev = ls->head->prev;
		tmp->next = ls->head;
		ls->head->prev->next = tmp;
		ls->head->prev = tmp;
		ls->tail = tmp;
	}
	ls->size++;
	tmp = NULL;
	free(tmp);
}

t_node	*del_node(t_list *ls)
{
	t_node	*cur;
	t_node	*tmp;

	cur = ls->head;
	tmp = ls->head->next;
	tmp->prev = ls->tail;
	ls->tail->next = tmp;
	cur->next = NULL;
	cur->prev = NULL;
	ls->head = tmp;
	ls->size--;
	return (cur);
}

void	reset_list(t_list *ls)
{
	t_node	*cur;
	t_node	*tmp;

	cur = ls->head;
	while (ls->size)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
		ls->size--;
	}
	ls->size--;
	ls->head = NULL;
	ls->tail = NULL;
	ls->size = 0;
	free(ls);
}
