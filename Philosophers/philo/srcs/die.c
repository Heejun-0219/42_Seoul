/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:08 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:43:47 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

void	die(t_state *info, int i, int j)
{
	while (info->satisfy_count == false)
	{
		i = 0;
		while (i < info->number_of)
		{
			if (gettime() - info->phi[i].last_eat > info->time_to_die)
			{
				print(info->phi[i].id, RED"died", info);
				info->died = true;
				if (info->number_of == 1)
				{
					while (++j < info->number_of)
						pthread_mutex_destroy(&info->fork_mutex[j]);
					pthread_mutex_destroy(&info->print_mutex);
					exit(0);
				}
			}
			i++;
		}
		if (info->died == true)
			break ;
	}
}
