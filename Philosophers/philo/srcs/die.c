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

void	die(t_state *aristo, int i, int j)
{
	while (aristo->eat_all == false)
	{
		i = 0;
		while (i < aristo->number_of)
		{
			if (gettime() - aristo->phi[i].last_eat > aristo->time_to_die)
			{
				print(aristo->phi[i].id, RED"Philosop died", aristo);
				aristo->died = true;
				if (aristo->number_of == 1)
				{
					while (++j < aristo->number_of)
						pthread_mutex_destroy(&aristo->fork_mutex[j]);
					pthread_mutex_destroy(&aristo->print_mutex);
					exit(0);
				}
			}
			i++;
		}
		if (aristo->died == true)
			break ;
	}
}
