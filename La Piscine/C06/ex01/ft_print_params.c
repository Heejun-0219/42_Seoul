/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:30:33 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/15 15:36:41 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 1)
		return (0);
	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
			write(1, &av[i][j++], 1);
		write(1, "\n", 1);
	}
	return (0);
}
