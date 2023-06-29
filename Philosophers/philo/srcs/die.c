/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:08 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:43:47 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

int	die(t_state *info, int i)
{
	long time;

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
			{
				print(info->phi[i].id, "died", info);
				pthread_mutex_lock(&info->died_mutex);
				info->died = 1;
				pthread_mutex_unlock(&info->died_mutex);
				destory(info, -1);
				return (1);
			}
			i++;
			usleep(100);
		}
		usleep(100);
		pthread_mutex_lock(&info->eat_satisft_mutex);
	}
	return (0);
}

void	destory(t_state *info, int i)
{
	pthread_mutex_unlock(&info->print_mutex);
	pthread_mutex_unlock(&info->eat_cnt_mutex);
	pthread_mutex_unlock(&info->eat_satisft_mutex);
	pthread_mutex_unlock(&info->died_mutex);
	pthread_mutex_unlock(&info->last_eat_mutex);
	while (++i < info->number_of){
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
