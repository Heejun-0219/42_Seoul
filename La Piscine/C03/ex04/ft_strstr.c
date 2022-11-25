/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:34:49 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/11 09:55:04 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp_index(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] == s2[i])
			++i;
		else
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (!(*to_find))
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (ft_strcmp_index(&str[i], to_find))
				return (str + i);
		}
		++i;
	}
	return (0);
}
