/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:08:38 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/05 16:20:36 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	get_index(t_pushswap *t, int *array)
{
	t_value	v;
	int		*arr;

	arr = array;
	v.a = -1;
	while (++v.a < t->a->size)
	{
		v.b = -1;
		while (++v.b < v.a)
		{
			if (arr[v.b] > arr[v.a])
			{
				v.c = arr[v.b];
				arr[v.b] = arr[v.a];
				arr[v.a] = v.c;
			}
			if (arr[v.b] == arr[v.a])
				error(2);
		}
	}
}

int	*get_array(t_pushswap *t)
{
	t_node	*cur;
	int		*array;
	int		i;

	array = (int *)malloc(sizeof(int) * (t->a->size));
	if (!array)
		error(0);
	i = 0;
	cur = t->a->head;
	while (cur != t->a->tail)
	{
		array[i] = cur->data;
		cur = cur->next;
		i++;
	}
	array[i] = cur->data;
	return (array);
}

int	checker(t_pushswap *t, int size)
{
	char	*line;
	int		gnl;

	gnl = get_next_line(0, &line);
	if (*line)
	{
		while (gnl > 0)
		{
			if (!ft_strcmp(line, "Error"))
				error(2);
			call_utils(t, line);
			free(line);
			gnl = get_next_line(0, &line);
		}
		if (gnl < 0)
			error(2);
	}
	free(line);
	return (is_sort(t, size));
}

int	main(int argc, char *argv[])
{
	t_pushswap	*t;
	int			size;
	int			result;

	if (argc < 2)
		exit(1);
	t = (t_pushswap *)malloc(sizeof(t_pushswap));
	init_pushswap(t);
	if (!t || !t->a || !t->b)
		error(0);
	if (!parsing_arg(argv, argc, t))
		error(1);
	size = t->a->size;
	result = checker(t, size);
	if (result == 0)
		write(1, "KO\n", 3);
	else if (result == 1 && t->b->size == 0)
		write(1, "OK\n", 3);
	else if (result == 1 && t->b->size != 0)
		write(1, "KO\n", 3);
	free_all(t);
	while (1)
		continue ;
	return (0);
}
