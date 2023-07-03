/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:02 by heejunki          #+#    #+#             */
/*   Updated: 2023/07/03 23:24:47 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

int	meal_time(t_phi *philo)
{
	if (print(philo->id, "is eating", philo->link) == 1)
		return (1);
	pthread_mutex_lock(&philo->link->last_eat_mutex);
	philo->last_eat = gettime();
	pthread_mutex_unlock(&philo->link->last_eat_mutex);
	if (pass_the_time(philo->link->time_to_eat, philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->link->eat_cnt_mutex);
	philo->count_eat++;
	pthread_mutex_unlock(&philo->link->eat_cnt_mutex);
	pthread_mutex_unlock(&philo->link->fork_mutex[philo->r_fork_id]);
	pthread_mutex_unlock(&philo->link->fork_mutex[philo->l_fork_id]);
	if (check_status(philo) == 1)
		return (1);
	return (0);
}

int	get_fork(t_phi *philo)
{
	if (philo->link->number_of == 1)
	{
		pthread_mutex_lock(&philo->link->fork_mutex[philo->r_fork_id]);
		print(philo->id, "has taken a fork", philo->link);
		pthread_mutex_unlock(&philo->link->fork_mutex[philo->r_fork_id]);
		return (1);
	}
	pthread_mutex_lock(&philo->link->fork_mutex[philo->r_fork_id]);
	if (print(philo->id, "has taken a fork", philo->link) == 1)
		return (1);
	pthread_mutex_lock(&philo->link->fork_mutex[philo->l_fork_id]);
	if (print(philo->id, "has taken a fork", philo->link) == 1)
		return (1);
	return (0);
}

int	set_satisfy(t_state *info, t_phi *philo)
{
	if (check_status(philo) == 1)
		return (1);
	pthread_mutex_lock(&info->eat_satisft_mutex);
	info->satisfy_count = 1;
	pthread_mutex_unlock(&info->eat_satisft_mutex);
	if (check_status(philo) == 1)
		return (1);
	return (1);
}

void	*start(void *data)
{
	t_phi	*philo;

	philo = (t_phi *)data;
	if (philo->id % 2)
		usleep(1000);
	while (check_status(philo) == 0)
	{
		if (get_fork(philo) == 1)
			if (ft_fork_unlock(philo) == 0)
				break ;
		if (meal_time(philo) == 1)
			if (ft_fork_unlock(philo) == 0)
				break ;
		if (print(philo->id, "is sleeping", philo->link) == 1)
			break ;
		if (philo->link->must_eat <= philo->count_eat
			&& philo->link->must_eat != -1)
			if (set_satisfy(philo->link, philo) == 1)
				break ;
		if (pass_the_time(philo->link->time_to_sleep, philo) == 1)
			break ;
		if (print(philo->id, "is thinking", philo->link) == 1)
			break ;
	}
	return (NULL);
}

int	create(t_state *info)
{
	int	i;

	i = -1;
	while (++i < info->number_of)
	{
		pthread_create(&info->phi[i].th_id, NULL, start, &info->phi[i]);
	}
	if (die(info) == 1)
	{
		return (1);
	}
	destory(info);
	return (0);
}
