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
	while (aristo->satisfy_count == false)
	{
		i = 0;
		while (i < aristo->number_of)
		{
			if (gettime() - aristo->phi[i].last_eat > aristo->time_to_die)
			{
				print(aristo->phi[i].id, RED"died", aristo);
				aristo->died = true;
			}
			i++;
		}
		if (aristo->died == true)
			break ;
	}
}
