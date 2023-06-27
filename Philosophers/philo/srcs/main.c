/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:24 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/27 14:43:10 by heejunki         ###   ########.fr       */
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
		ft_error("Bad number of arg...");
		return (1);
	}
	if(ph_init(info, ac, av, 0) == 1)
		return (1);
	create(info, -1, -1);
	return (0);
}
