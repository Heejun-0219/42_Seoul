/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:50 by heejunki          #+#    #+#             */
/*   Updated: 2023/07/03 20:24:35 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

int	check_status(t_phi *phi)
{
	pthread_mutex_lock(&phi->link->died_mutex);
	if (phi->link->died == 1)
	{
		pthread_mutex_unlock(&phi->link->died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&phi->link->died_mutex);
	return (0);
}

int	ft_error(char *s)
{
	printf("%s", s);
	return (1);
}

int	ft_fork_unlock(t_phi *phi)
{
	pthread_mutex_unlock(&phi->link->eat_mutex[phi->r_fork_id]);
	pthread_mutex_unlock(&phi->link->fork_mutex[phi->r_fork_id]);
	pthread_mutex_unlock(&phi->link->eat_mutex[phi->l_fork_id]);
	pthread_mutex_unlock(&phi->link->fork_mutex[phi->l_fork_id]);
	return (0);
}

int	print(int id, char *s, t_state *info)
{
	int	st;

	pthread_mutex_lock(&info->died_mutex);
	st = info->died;
	pthread_mutex_unlock(&info->died_mutex);
	if (st == 0)
	{
		pthread_mutex_lock(&info->print_mutex);
		printf("%lu %d %s\n", \
			gettime() - info->start_time, id + 1, s);
		pthread_mutex_unlock(&info->print_mutex);
		return (0);
	}
	return (1);
}

int	ft_atoi(char *s)
{
	int	res;
	int	sing;
	int	i;

	res = 0;
	sing = 1;
	i = -1;
	while (s[++i])
		if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-'))
			return (-1);
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sing = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - 48);
	return (res * sing);
}
