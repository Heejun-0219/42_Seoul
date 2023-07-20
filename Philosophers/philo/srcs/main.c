/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:24 by heejunki          #+#    #+#             */
/*   Updated: 2023/07/20 14:16:23 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

void	free_all(t_state *info)
{
	free(info->phi);
	free(info->fork_mutex);
	free(info);
}

int	main(int ac, char **av)
{
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
	{
		free_all(info);
		return (FAILURE);
	}
	if (create(info) == FAILURE)
		return (FAILURE);
	free_all(info);
	return (SUCCESS);
}
