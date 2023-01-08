/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:47:54 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/19 15:15:54 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_over(long num, const char c, int minus)
{
	if (num > INT_MAX / 10 || (num == INT_MAX / 10 && c - '0' > 7))
	{
		if (minus == 1)
			return (-1);
		return (0);
	}
	return (1);
}

long	overflow_check(const char *str)
{
	long	num;
	int		minus;

	num = 0;
	minus = 1;
	if (*(str) == '-' || *(str) == '+')
		if (*(str++) == '-')
			minus *= -1;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str++ - '0');
	}
	return (num * minus);
}
