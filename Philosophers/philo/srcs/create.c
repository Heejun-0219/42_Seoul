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
	print(philo->id, "is eating", philo->link);
	pthread_mutex_lock(&philo->link->last_eat_mutex);
	philo->last_eat = gettime();
	pthread_mutex_unlock(&philo->link->last_eat_mutex);
	pass_the_time(philo->link->time_to_eat);
	pthread_mutex_lock(&philo->link->eat_cnt_mutex);
	philo->count_eat++;
	pthread_mutex_unlock(&philo->link->eat_cnt_mutex);
	pthread_mutex_unlock(&philo->link->fork_mutex[philo->r_fork_id]);
	pthread_mutex_unlock(&philo->link->fork_mutex[philo->l_fork_id]);
}

int	get_fork(t_phi *philo){
	if (philo->link->number_of == 1)
	{
		pthread_mutex_lock(&philo->link->fork_mutex[philo->r_fork_id]);
		print(philo->id, "has taken a right fork", philo->link);
		pthread_mutex_unlock(&philo->link->fork_mutex[philo->r_fork_id]);
		return (1);
	}
	pthread_mutex_lock(&philo->link->fork_mutex[philo->r_fork_id]);
	print(philo->id, "has taken a right fork", philo->link);
	pthread_mutex_lock(&philo->link->fork_mutex[philo->l_fork_id]);
	print(philo->id, "has taken a left fork", philo->link);
	return (0);
}

int	check_status(t_phi *phi)
{
	int	st;

	pthread_mutex_lock(&phi->link->died_mutex);
	st = phi->link->died;
	pthread_mutex_unlock(&phi->link->died_mutex);
	if (st == 1)
		return (1);
	return (0);
}

void	*start(void *data)
{
	t_phi	*philo;

	philo = (t_phi *)data;
	if (philo->id % 2)
		usleep(100);
	while (check_status(philo) == 0)
	{
		if (get_fork(philo) == 1)
			break ;
		if (check_status(philo) == 1)
			break ;
		meal_time(philo);
		if (check_status(philo) == 1)
			break ;
		print(philo->id, "is sleeping", philo->link);
		if (check_status(philo) == 1)
			break ;
		pthread_mutex_lock(&philo->link->eat_cnt_mutex);
		if (philo->link->must_eat != -1
			&& philo->link->must_eat <= philo->count_eat)
		{
			philo->link->satisfy_count = 1;
			break ;
		}
		pthread_mutex_unlock(&philo->link->eat_cnt_mutex);
		if (check_status(philo) == 1)
			break ;
		pass_the_time(philo->link->time_to_sleep);
		if (check_status(philo) == 1)
			break ;
		print(philo->id, "is thinking", philo->link);
	}
	return (NULL);
}

void	destory(t_state *info, int i)
{
	while (++i < info->number_of)
		pthread_join(info->phi[i].th_id, NULL);
	i = -1;
	while (++i < info->number_of)
		pthread_mutex_destroy(&info->fork_mutex[i]);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->eat_cnt_mutex);
	pthread_mutex_destroy(&info->died_mutex);
	pthread_mutex_destroy(&info->last_eat_mutex);
}

int	create(t_state *info, int i)
{
	while (++i < info->number_of)
	{
		pthread_create(&info->phi[i].th_id, NULL, start, &info->phi[i]);
	}
	if (die(info, 0) == 1)
	{
		destory(info, -1);
		return (1);
	}
	destory(info, -1);
	return (0);
}
