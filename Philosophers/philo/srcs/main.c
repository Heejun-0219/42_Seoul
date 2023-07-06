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

int	main(int ac, char **av)
{
	t_state	*info;

	info = malloc(sizeof(t_state));
	if (!info)
		return (FAILURE);
	if (ac != 5 && ac != 6)
	{
		ft_error("Error: Invalid argument");
		return (FAILURE);
	}
	if (ph_init(info, ac, av) == FAILURE)
		return (FAILURE);
	if (create(info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
