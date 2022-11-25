/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:15:04 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/20 11:42:27 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*p;

	p = (int *) malloc(sizeof(int) * length);
	if (!p)
		return (0);
	i = 0;
	while (i < length)
	{
		p[i] = (*f)(tab[i]);
		++i;
	}
	return (p);
}
