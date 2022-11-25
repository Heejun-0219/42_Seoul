/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 06:54:29 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/04 09:41:22 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int a, int b, int c, int d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(a == '9' && b == '8'))
	{
		write(1, ", ", 2);
	}
}

int	ft_change_num_beh(char *c, char *d)
{
	if (*d > '9')
	{
		if (*c == '9')
		{
			return (1);
		}
		++(*c);
		*d = '0';
	}
	return (0);
}

void	ft_change_num_frt(char *a, char *b)
{
	if (*b == '9')
	{
		++(*a);
		*b = '0';
	}
	else
		++(*b);
}

void	ft_print_comb2(void)
{
	char	frt1;
	char	frt2;
	char	beh1;
	char	beh2;

	frt1 = '0';
	frt2 = '0';
	beh1 = '0';
	while (frt1 <= '9')
	{
		beh2 = frt2 + 1;
		while (beh1 <= '9')
		{
			if (ft_change_num_beh(&beh1, &beh2))
				break ;
			ft_print_num(frt1, frt2, beh1, beh2);
			++beh2;
		}
		ft_change_num_frt(&frt1, &frt2);
		beh1 = frt1;
	}
}
