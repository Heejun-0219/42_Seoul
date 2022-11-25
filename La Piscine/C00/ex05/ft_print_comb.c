/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 08:30:38 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/11 06:10:14 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_th_num(int a, int b, int c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0 + '0';
	while (a < 7 + '0')
	{
		b = a + 1;
		while (b < 9 + '0')
		{
			c = b + 1;
			while (c < 10 + '0')
			{
				print_th_num(a, b, c);
				++c;
				write(1, ", ", 2);
			}
			++b;
		}
		++a;
	}
	b = a + 1;
	c = b + 1;
	print_th_num(a, b, c);
}
