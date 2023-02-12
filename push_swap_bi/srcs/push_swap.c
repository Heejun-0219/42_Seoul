/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:45 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/04 12:10:47 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	temp()
{
	system("leaks push_swap");
}
int	main(int argc, char **argv)
{
	t_pushswap	*t;

	if (argc < 2)
		exit(1);
	t = (t_pushswap *)malloc(sizeof(t_pushswap));
	init_pushswap(t);
	if (!t || !t->a || !t->b)
		error(0);
	if (!parsing_arg(argv, argc, t))
		error(1);
	if (t->a->size <= 5)
		short_a(t);
	if (t->a->size > 5)
	{
		get_lis(t);
		a_to_b(t);
		b_to_a(t);
	}
	reset_list(t->a);
	reset_list(t->b);
	free(t);
	return (0);
}
