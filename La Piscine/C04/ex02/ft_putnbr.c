/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:17:49 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/15 11:49:49 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print(char num)
{
	write(1, &num, 1);
}

void	ft_putnbr(int nb)
{
	char	num;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		ft_putnbr(nb);
	}
	else if (nb <= 9)
	{
		num = nb + '0';
		ft_print(num);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
