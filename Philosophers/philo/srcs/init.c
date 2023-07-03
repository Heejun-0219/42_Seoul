/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:05:15 by heejunki          #+#    #+#             */
/*   Updated: 2023/07/03 20:19:01 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

int	check(t_state *info)
{
	if (info->time_to_die < 60 || info->number_of < 1
		|| info->time_to_die < 60 || info->time_to_sleep < 60
		|| info->number_of > 200 || info->must_eat < -1
		|| info->must_eat == 0)
	{
		ft_error("Error: Invalid argument value");
		return (1);
	}
	return (0);
}

int	ind_init(t_state *info)
{
	int	i;

	i = 0;
	info->phi = malloc(sizeof(t_phi) * info->number_of);
	if (!info->phi)
		return (1);
	while (i < info->number_of)
	{
		info->phi[i].id = i;
		info->phi[i].count_eat = 0;
		info->phi[i].l_fork_id = i;
		info->phi[i].r_fork_id = (i + 1) % info->number_of;
		info->phi[i].link = info;
		info->phi[i].last_eat = gettime();
		i++;
	}
	return (0);
}

void	th_init(t_state *info)
{
	int	begin;

	begin = 0;
	pthread_mutex_init(&info->print_mutex, NULL);
	pthread_mutex_init(&info->eat_cnt_mutex, NULL);
	pthread_mutex_init(&info->eat_satisft_mutex, NULL);
	pthread_mutex_init(&info->died_mutex, NULL);
	pthread_mutex_init(&info->last_eat_mutex, NULL);
	while (begin < info->number_of)
	{
		pthread_mutex_init(&info->fork_mutex[begin++], NULL);
		pthread_mutex_init(&info->eat_mutex[begin++], NULL);
	}
}

int	ph_init(t_state *info, int ac, char **av)
{
	info->number_of = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	if (check(info) == 1)
		return (1);
	info->start_time = gettime();
	info->died = 0;
	info->satisfy_count = 0;
	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * info->number_of);
	if (!info->fork_mutex)
		return (1);
	info->eat_mutex = malloc(sizeof(pthread_mutex_t) * info->number_of);
	if (!info->eat_mutex)
		return (1);
	th_init(info);
	if (ind_init(info) == 1)
		return (1);
	return (0);
}
