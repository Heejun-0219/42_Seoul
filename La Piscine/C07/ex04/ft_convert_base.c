/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:49:10 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/19 08:05:14 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	check_string(char *base, int base_len);
int	find_base(char *str, char *base, int i, int base_len);
int	find_result(char *str, char *base, int base_len);
int	ft_atoi_base(char *str, char *base);

int	count_nbrlen(long long nb, int to_len)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		++i;
		nb = nb / to_len;
	}
	if (i)
		return (i);
	else
		return (1);
}

char	*find_val(char *p, long long nbr, char *base, int index)
{
	int	len;

	len = ft_strlen(base);
	if (len > nbr)
		p[index - 1] = base[nbr];
	else
	{
		find_val(p, nbr % len, base, index);
		find_val(p, nbr / len, base, index - 1);
	}
	return (p);
}

char	*ft_putnbr(long long nbr, char *base)
{
	int		nb_len;
	char	*p;

	nb_len = count_nbrlen(nbr, ft_strlen(base));
	if (nbr < 0)
	{
		nbr *= -1;
		nb_len++;
		p = (char *)malloc(sizeof(char) * (nb_len + 1));
		p[0] = '-';
	}
	else
		p = (char *)malloc(sizeof(char) * (nb_len + 1));
	p[nb_len] = '\0';
	find_val(p, nbr, base, nb_len);
	return (p);
}

char	*ft_putnbr_base(long long nbr, char *base)
{
	int		len;
	char	*p;

	len = ft_strlen(base);
	if (check_string(base, len) == 0)
		return (0);
	else
		p = ft_putnbr(nbr, base);
	return (p);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	num;
	char		*p;

	if (!check_string(base_from, ft_strlen(base_from)))
		return (0);
	else if (!check_string(base_to, ft_strlen(base_to)))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	p = ft_putnbr_base(num, base_to);
	return (p);
}
