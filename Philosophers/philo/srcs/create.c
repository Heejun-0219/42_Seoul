/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:02 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:43:51 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

void	meal_time(t_phi *philo)
{
	pthread_mutex_lock(&philo->link->fork_mutex[philo->r_fork_id]);
	print(philo->id, PURPLE"has taken a right fork", philo->link);
	pthread_mutex_lock(&philo->link->fork_mutex[philo->l_fork_id]);
	print(philo->id, PURPLE"has taken a left fork", philo->link);
	print(philo->id, GREEN"is eating", philo->link);
	philo->last_eat = gettime();
	pass_the_time(philo->link->time_to_eat, philo->link);
	pthread_mutex_unlock(&philo->link->fork_mutex[philo->r_fork_id]);
	pthread_mutex_unlock(&philo->link->fork_mutex[philo->l_fork_id]);
	philo->count_eat++;
}

void	*start(void *data)
{
	t_phi	*philo;

	philo = (t_phi *)data;
	if (philo->id % 2)
		usleep(100);
	while (philo->link->died == false)
	{
		if (philo->link->died == true)
			break ;
		meal_time(philo);
		if (philo->link->must_eat != -1
			&& philo->link->must_eat <= philo->count_eat)
		{
			philo->link->satisfy_count = true;
			break ;
		}
		if (philo->link->died == true)
			break ;
		print(philo->id, BLUE"is sleeping", philo->link);
		pass_the_time(philo->link->time_to_sleep, philo->link);
		if (philo->link->died == true)
			break ;
		print(philo->id, YELLOW"is thinking", philo->link);
	}
	return (NULL);
}

int	create(t_state *info, int i, int j)
{
	while (++i < info->number_of)
	{
		pthread_create(&info->phi[i].th_id, NULL, start, &info->phi[i]);
	}
	if (die(info, 0, -1) == 1)
		return (1);
	while (++j < info->number_of)
		pthread_join(info->phi[j].th_id, NULL);
	j = -1;
	while (++j < info->number_of)
		pthread_mutex_destroy(&info->fork_mutex[j]);
	pthread_mutex_destroy(&info->print_mutex);
	return (0);
}
