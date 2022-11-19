/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:11:33 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/12 11:56:21 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_minus(char *str, int *i)
{
	int	minus;

	minus = 1;
	while (str[*i])
	{
		if (str[*i] == '-')
		{
			minus *= -1;
			++(*i);
		}
		else if (str[*i] == '+')
			++(*i);
		else
			break ;
	}
	return (minus);
}

int	ft_atoi(char *str)
{
	int	minus;
	int	num;
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			++i;
		else
			break ;
	}
	minus = check_minus(str, &i);
	num = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			break ;
		num = num * 10 + (str[i] - '0');
		++i;
	}
	return (num * minus);
}
