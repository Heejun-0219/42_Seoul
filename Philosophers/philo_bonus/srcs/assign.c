/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:02:54 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:43:47 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi_b.h"

void	*hospital(void *data)
{
	t_phis	*philo;
	t_state	*all;

	philo = (t_phis *)data;
	all = philo->link;
	while (true)
	{
		if (philo->eat_count == all->must_eat)
			break ;
		if (gettime() - philo->last_eat > all->time_die)
		{
			print(philo->id, "\033[0;91mPhilosop died", all);
			all->is_died = true;
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	birth(t_phis *philo)
{
	if (philo->id % 2 == 0)
		usleep(1000);
	philo->last_eat = gettime();
	pthread_create(&philo->link->yep, NULL, hospital, philo);
	while (philo->link->is_died == false)
	{
		meal_time(philo);
		if (philo->eat_count == philo->link->must_eat)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	exit(1);
}

void	process(t_state *all)
{
	int	idx;

	idx = -1;
	while (++idx < all->number_of)
	{
		all->philo[idx].pid = fork();
		if (all->philo[idx].pid < 0)
			ft_exit("Error! Fork");
		if (all->philo[idx].pid == 0)
			birth(&all->philo[idx]);
		usleep(100);
	}
	pthread_create(&all->check, NULL, waitp, all);
	pthread_join(all->check, NULL);
}
