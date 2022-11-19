/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:20:48 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/15 11:50:12 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_string(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putnbr(long long nbr, char *base, int len)
{
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		ft_putnbr(nbr, base, len);
	}
	else if (nbr < len)
		write(1, &base[nbr], 1);
	else
	{
		ft_putnbr(nbr / len, base, len);
		ft_putnbr(nbr % len, base, len);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (check_string(base, len) == 0)
		return ;
	else
		ft_putnbr((long long)nbr, base, len);
}
