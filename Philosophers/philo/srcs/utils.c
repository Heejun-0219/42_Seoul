/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:50 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:43:47 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

int ft_error(char *s)
{
	printf("%s", s);
	return (1);
}

void print(int id, char *s, t_state *info)
{
	int st;

	pthread_mutex_lock(&info->died_mutex);
	st = info->died;
	pthread_mutex_unlock(&info->died_mutex);
	if (st == 0)
	{
		pthread_mutex_lock(&info->print_mutex);
		printf("%llu ~ Num: %d philosopher %s\n", \
			gettime() - info->start_time, id, s);
		pthread_mutex_unlock(&info->print_mutex);
	}
}

uint64_t ft_atoi(char *s)
{
	uint64_t res;
	uint64_t sing;
	int i;
	int j;

	res = 0;
	sing = 1;
	i = 0;
	j = -1;
	while (s[++j])
		if (s[j] < '0' || s[j] > '9'){
			ft_error("Error: Invalid argument\n");
			return (-1);
		}
	while (s[i] <= 32)
		i++;
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
