/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:03:09 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:43:47 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phi_b.h"

int	main(int ac, char **av)
{
	t_state	*all;

	all = (t_state *)malloc(sizeof(t_state));
	if (ac != 5 && ac != 6)
		ft_exit("Bad number of arguman");
	init_arguments(all, ac, av);
	process(all);
}
