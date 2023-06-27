/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:03:41 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/27 14:43:09 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi_b.h"

void	check(t_state *all)
{
	if (all->time_die < 60 || all->number_of < 1
		|| all->time_die < 60 || all->time_sleep < 60 || all->number_of > 200)
		ft_exit("Error! Bad numbers of argument");
}

void	ph_initilos(t_state *all, int idx)
{
	all->philo = malloc(sizeof(t_phis) * all->number_of);
	while (++idx < all->number_of)
	{
		all->philo[idx].id = idx;
		all->philo[idx].eat_count = 0;
		all->philo[idx].last_eat = gettime();
		all->philo[idx].link = all;
	}
}

void	init_sem(t_state *all)
{
	sem_unlink("./print");
	sem_unlink("./forks");
	all->forks = sem_open("./forks", O_CREAT, S_IRWXG, all->number_of);
	all->print = sem_open("./print", O_CREAT, S_IRWXG, 1);
	if (all->forks == SEM_FAILED || all->print == SEM_FAILED)
		ft_exit("Error! Sem_Open");
}

void	init_arguments(t_state *all, int ac, char **av)
{
	all->number_of = ft_atoi(av[1]);
	all->time_die = ft_atoi(av[2]);
	all->time_eat = ft_atoi(av[3]);
	all->time_sleep = ft_atoi(av[4]);
	if (ac < 6)
		all->must_eat = -1;
	else
		all->must_eat = ft_atoi(av[5]);
	all->start_time = gettime();
	all->is_died = false;
	all->all_eat = false;
	check(all);
	ph_initilos(all, -1);
	init_sem(all);
}
