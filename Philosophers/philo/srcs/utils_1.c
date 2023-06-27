/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:42 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:43:47 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

uint64_t	gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	print(int id, char *s, t_state *aristo)
{
	if (aristo->died == false)
	{
		pthread_mutex_lock(&aristo->random);
		printf(WHITE"%llu -> timestamp_in_ms ~ ",
			(gettime() - aristo->start_time));
		printf(SKY"%d. philosop -> %s\n", id, s);
		pthread_mutex_unlock(&aristo->random);
	}
}

void	pass_the_time(int time, t_state *aristo)
{
	uint64_t	start;

	start = gettime();
	while (aristo->died == false)
	{
		if (gettime() - start >= time)
			break ;
		usleep(42);
	}
}
