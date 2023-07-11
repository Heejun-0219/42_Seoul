/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:24 by heejunki          #+#    #+#             */
/*   Updated: 2023/07/06 13:28:53 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

void ft_exit(void)
{
	// free
	system("leaks philo");
}

void free_all(t_state *info)
{
	free(info->phi);
	free(info->fork_mutex);
	free(info);
}

int	main(int ac, char **av)
{
	atexit(ft_exit);
	t_state	*info;

	if (ac != 5 && ac != 6)
	{
		ft_error("Error: Invalid argument");
		return (FAILURE);
	}
	info = malloc(sizeof(t_state));
	if (!info)
		return (FAILURE);
	if (ph_init(info, ac, av) == FAILURE)
		return (FAILURE);
	if (create(info) == FAILURE)
		return (FAILURE);
	free_all(info);
	return (SUCCESS);
}
