/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:24 by heejunki          #+#    #+#             */
/*   Updated: 2023/07/03 23:21:12 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

int	main(int ac, char **av)
{
	t_state	*info;

	info = malloc(sizeof(t_state));
	if (!info)
		return (0);
	if (ac != 5 && ac != 6)
	{
		ft_error("Error: Invalid argument");
		return (1);
	}
	if (ph_init(info, ac, av) == 1)
		return (1);
	if (create(info) == 1)
		return (1);
	return (0);
}
