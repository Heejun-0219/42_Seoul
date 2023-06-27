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

int	ft_error(char *s)
{
	printf("%s", s);
	return (1);
}

void	print(int id, char *s, t_state *info)
{
	if (info->died == false)
	{
		pthread_mutex_lock(&info->print_mutex);
		printf(WHITE"%llu ~ ",
			gettime() - info->start_time);
		printf(SKY"Num: %d philosopher %s\n", id, s);
		pthread_mutex_unlock(&info->print_mutex);
	}
}

static int	check_max_or_min(long num, const char c, int minus)
{
	if (num > LONG_MAX / 10 || (num == LONG_MAX / 10 && c - '0' > 7))
	{
		if (minus == 1)
			return (-1);
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		minus;

	num = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*(str) == '-' || *(str) == '+')
		if (*(str++) == '-')
			minus *= -1;
	while (*str >= '0' && *str <= '9')
	{
		if (check_max_or_min(num, *str, minus) != 1)
			return (check_max_or_min(num, *str, minus));
		num = num * 10 + (*str++ - '0');
	}
	return (num * minus);
}
