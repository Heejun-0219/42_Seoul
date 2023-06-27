/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:03:28 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:44:48 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi_b.h"

void	meal_time(t_phis *philo)
{
	t_state	*all;

	all = philo->link;
	sem_wait(all->forks);
	print(philo->id, PURPLE"took the right fork", all);
	sem_wait(all->forks);
	print(philo->id, PURPLE"took the left fork", all);
	print(philo->id, GREEN"Eating", all);
	pass_the_time(philo->link->time_eat, philo->link);
	philo->last_eat = gettime();
	philo->eat_count++;
	sem_post(all->forks);
	sem_post(all->forks);
}

void	philo_sleep(t_phis *philo)
{
	t_state	*all;

	all = philo->link;
	print(philo->id, BLUE"Sleeping", philo->link);
	pass_the_time(all->time_sleep, all);
}

void	philo_think(t_phis *philo)
{
	print(philo->id, YELLOW"Thinking", philo->link);
}
