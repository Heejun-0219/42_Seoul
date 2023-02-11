/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:53:19 by heejunki          #+#    #+#             */
/*   Updated: 2023/02/11 09:47:26 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// printf value 삭제 필수 
void	ft_lstprint(t_list *val)
{
	while (val)
	{
		printf("%d ", val->content);
		val = val->next;
	}
	printf("\n\n");
}

void	list_free(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}	

void	sorting(t_list **a, t_list **b, int size)
{
	int	*lis;
	int	*data_copy;
	int	max;

	if (size == 3)
	{
		three_size_sorting(a);
		return ;
	}
	else if (size == 5)
	{
		five_size_sorting(a, b);
		return ;
	}
	data_copy = list_data_copy(*a, size);
	max = 1;
	lis = count_lis(data_copy, size, &max);
	move_to_b(a, b, lis, max);
	move_to_a(a, b);
	rotate_to_start(a, size);
	ft_lstprint(*a);
	free(data_copy);
	free(lis);
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
	sorting(&a, &b, size);
	if (ac == 2)
		free(parameter);
	list_free(a);
	list_free(b);
	return (0);
}
