/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:30:28 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/15 23:46:55 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*range;
	long long	len;
	long long	i;

	i = 0;
	len = (long long)max - (long long)min;
	if (min >= max)
		return (0);
	range = (int *) malloc (sizeof (int) * len);
	while (len != 0)
	{
		range[i] = min + i;
		i++;
		len--;
	}
	return (range);
}
