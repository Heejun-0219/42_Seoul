/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:15 by heejunki          #+#    #+#             */
/*   Updated: 2023/08/01 18:47:06 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

int	check(t_state *info)
{
	if (info->number_of < 1 || info->must_eat < -1 \
		|| info->time_to_die < 0 || info->time_to_eat < 0 \
		|| info->time_to_sleep < 0 || info->must_eat == 0)
	{
		ft_error("Error: Invalid argument value");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ind_init(t_state *info)
{
	int	i;

	i = 0;
	info->phi = malloc(sizeof(t_phi) * info->number_of);
	if (!info->phi)
		return (FAILURE);
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
	return (SUCCESS);
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
		pthread_mutex_init(&info->fork_mutex[begin++], NULL);
}

int	ph_init(t_state *info, int ac, char **av)
{
	info->number_of = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->start_time = gettime();
	info->died = 0;
	info->satisfy_count = 0;
	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * info->number_of);
	if (!info->fork_mutex)
		return (ft_error("Error: Invalid argument value"));
	th_init(info);
	if (ind_init(info) == FAILURE)
		return (FAILURE);
	if (ac == 6)
	{
		info->must_eat = ft_atoi(av[5]);
		if (info->must_eat == -1)
			return (ft_error("Error: Invalid argument value"));
	}
	else
		info->must_eat = -1;
	if (check(info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
