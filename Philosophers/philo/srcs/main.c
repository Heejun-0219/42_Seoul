/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:05:24 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/27 14:41:07 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi.h"

int	main(int ac, char **av)
{
	t_state	*aristo;

	aristo = malloc(sizeof(t_state));
	if (!aristo)
		return (0);
	if (ac != 5 && ac != 6)
		ft_exit("Bad number of arg...");
	ft_init(aristo, ac, av, 0);
	create_thread(aristo, -1, -1);
	return (0);
}
