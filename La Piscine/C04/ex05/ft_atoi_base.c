/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:54:20 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/15 11:50:37 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	check_string(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

int	find_base(char *str, char *base, int i, int base_len)
{
	int	index;

	index = 0;
	while (index < base_len)
	{
		if (base[index] == str[i])
			return (index);
		index++;
	}
	return (-1);
}

int	find_result(char *str, char *base, int base_len)
{
	int	i;
	int	odd;
	int	result;

	i = 0;
	odd = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			odd *= -1;
		i++;
	}
	while (find_base(str, base, i, base_len) != -1)
	{
		result = result * base_len + find_base(str, base, i, base_len);
		i++;
	}
	return (result * odd);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (check_string(base, base_len) == 0)
		return (0);
	else
		return (find_result(str, base, base_len));
}
