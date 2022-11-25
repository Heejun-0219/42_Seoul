/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:16:07 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/20 12:31:49 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft.h"

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
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	ft_c_strcmp(char c, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (c == s2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	int	num;
	int	odd;

	num = 0;
	odd = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			odd *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - '0');
	while (*str)
		break ;
	return (num * odd);
}

void	cal(int a, char *op, int b)
{
	int	(*f[5])(int, int);
	int	result;
	int	cho_oper;

	cho_oper = ft_c_strcmp(*op, "+-*/%");
	f[0] = op_plus;
	f[1] = op_minus;
	f[2] = op_multi;
	f[3] = op_div;
	f[4] = op_mod;
	if (cho_oper != -1)
	{
		result = f[cho_oper](a, b);
		ft_putnbr(result);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
}
