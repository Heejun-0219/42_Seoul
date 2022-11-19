/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:31:27 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/16 00:37:59 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	len;
	long long	i;

	i = 0;
	len = (long long)max - (long long)min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof (int) * len);
	if (!(*range))
		return (-1);
	while (len != 0)
	{
		(*range)[i] = min + i;
		i++;
		len--;
	}
	return ((int)i);
}
