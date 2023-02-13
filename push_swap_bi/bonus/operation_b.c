/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:13:09 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 12:05:11 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_pushswap *t)
{
	swap(t, 'a');
	swap(t, 'b');
}

void	rr(t_pushswap *t)
{
	rotate(t, 'a');
	rotate(t, 'b');
}

void	rrr(t_pushswap *t)
{
	reverse_rotate(t, 'a');
	reverse_rotate(t, 'b');
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
