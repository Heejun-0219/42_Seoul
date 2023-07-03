/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:42 by heejunki          #+#    #+#             */
/*   Updated: 2023/07/03 23:20:30 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

long	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (long)1000) + (tv.tv_usec / 1000));
}

int	pass_the_time(long time, t_phi *philo)
{
	long	start;

	if (check_status(philo) == 1)
		return (1);
	start = gettime();
	if (check_status(philo) == 1)
		return (1);
	while (start + time > gettime())
	{
		if (check_status(philo) == 1)
			return (1);
		usleep(1000);
	}
	if (check_status(philo) == 1)
		return (1);
	return (0);
}
