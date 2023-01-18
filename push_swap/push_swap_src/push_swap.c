/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:53:19 by heejunki          #+#    #+#             */
/*   Updated: 2023/01/19 00:49:04 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// printf value
void	ft_lstprint(t_list *val)
{
	while (val)
	{
		printf("%d ", val->content);
		val = val->next;
	}
	printf("\n\n");
}

void	insert_stack(t_list **stack, char **val)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = NULL;
	while (val[i])
	{
		tmp = ft_lstnew(ft_atoi(val[i]));
		ft_lstadd_back(stack, tmp);
		i++;
	}
	ft_lst_order(stack);
	ft_lst_inverted(stack);
	tmp = NULL;
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;
	char	**parameter;

	if (ac < 2)
		eexit();
	if (ac == 2)
		parameter = ft_split(av[1], ' ');
	else
		parameter = ++av;
	size = param_check(parameter);
	if (size == 2)
		return (0);
	a = NULL;
	b = NULL;
	insert_stack(&a, parameter);

	//ft_lstprint(a);
	return (0);
}
