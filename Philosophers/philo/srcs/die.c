/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:08 by heejunki          #+#    #+#             */
/*   Updated: 2023/07/03 23:22:27 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

static int	die_print(t_state *info, int i)
{
	pthread_mutex_lock(&info->died_mutex);
	info->died = 1;
	// print(info->phi[i].id, "died", info);
	printf("%lu %d died\n", gettime() - info->start_time, info->phi[i].id + 1);
	pthread_mutex_unlock(&info->died_mutex);
	destory(info);
	return (1);
}

int	die(t_state *info)
{
	long	time;
	int		i;

	pthread_mutex_lock(&info->eat_satisft_mutex);
	while (info->satisfy_count == 0)
	{
		pthread_mutex_unlock(&info->eat_satisft_mutex);
		i = 0;
		while (i < info->number_of)
		{	
			pthread_mutex_lock(&info->last_eat_mutex);
			time = gettime() - info->phi[i].last_eat;
			pthread_mutex_unlock(&info->last_eat_mutex);
			if (time > info->time_to_die)
				return (die_print(info, i));
			i++;
		}
		usleep(1000);
		pthread_mutex_lock(&info->eat_satisft_mutex);
	}
	return (0);
}

void	destory(t_state *info)
{
	int	i;

	i = -1;
	while (++i < info->number_of)
	{
		pthread_mutex_unlock(&info->print_mutex);
		pthread_mutex_unlock(&info->eat_cnt_mutex);
		pthread_mutex_unlock(&info->eat_satisft_mutex);
		pthread_mutex_unlock(&info->died_mutex);
		pthread_mutex_unlock(&info->last_eat_mutex);
		pthread_mutex_unlock(&info->fork_mutex[i]);
		pthread_join(info->phi[i].th_id, NULL);
	}
	i = -1;
	while (++i < info->number_of)
		pthread_mutex_destroy(&info->fork_mutex[i]);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_cnt_mutex);
	pthread_mutex_destroy(&info->eat_satisft_mutex);
	pthread_mutex_destroy(&info->died_mutex);
	pthread_mutex_destroy(&info->last_eat_mutex);
}
