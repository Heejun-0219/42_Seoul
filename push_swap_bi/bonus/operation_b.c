/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:13:09 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/02 14:17:48 by jaewpark         ###   ########.fr       */
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
