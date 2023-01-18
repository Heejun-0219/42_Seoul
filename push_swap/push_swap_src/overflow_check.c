/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:47:54 by heejunki          #+#    #+#             */
/*   Updated: 2023/01/18 23:00:19 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
