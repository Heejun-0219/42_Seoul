/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:21:33 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/02 13:34:23 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_pushswap *t)
{
	swap(t, 'a');
	swap(t, 'b');
	write(1, "ss\n", 3);
}

void	rr(t_pushswap *t)
{
	rotate(t, 'a');
	rotate(t, 'b');
	write(1, "rr\n", 3);
}

void	rrr(t_pushswap *t)
{
	reverse_rotate(t, 'a');
	reverse_rotate(t, 'b');
	write(1, "rrr\n", 4);
}

int	ft_strcmp(char *a, char *b)
{
	while (*a != '\0' || *b != '\0')
	{
		if (*a > *b)
			return (1);
		else if (*a < *b)
			return (-1);
		else
		{
			a++;
			b++;
		}
	}
	return (0);
}

void	call_utils(t_pushswap *t, char *alpha)
{
	if (ft_strcmp(alpha, "sa") == 0 && swap(t, 'a'))
		write(1, "sa\n", 3);
	if (ft_strcmp(alpha, "sb") == 0 && swap(t, 'b'))
		write(1, "sb\n", 3);
	if (ft_strcmp(alpha, "ra") == 0 && rotate(t, 'a'))
		write(1, "ra\n", 3);
	if (ft_strcmp(alpha, "rb") == 0 && rotate(t, 'b'))
		write(1, "rb\n", 3);
	if (ft_strcmp(alpha, "rra") == 0 && reverse_rotate(t, 'a'))
		write(1, "rra\n", 4);
	if (ft_strcmp(alpha, "rrb") == 0 && reverse_rotate(t, 'b'))
		write(1, "rrb\n", 4);
	if (ft_strcmp(alpha, "ss") == 0)
		ss(t);
	if (ft_strcmp(alpha, "rr") == 0)
		rr(t);
	if (ft_strcmp(alpha, "rrr") == 0)
		rrr(t);
	if (ft_strcmp(alpha, "pa") == 0)
		push(t, 'a');
	if (ft_strcmp(alpha, "pb") == 0)
		push(t, 'b');
}
