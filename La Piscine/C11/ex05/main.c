/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:01:39 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/20 12:34:09 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac != 4)
		return (0);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (b == 0 && av[2][0] == '/')
		write(1, "Stop : division by zero\n", 24);
	else if (b == 0 && av[2][0] == '%')
		write(1, "Stop : modulo by zero\n", 22);
	else
		cal(a, av[2], b);
	return (0);
}
