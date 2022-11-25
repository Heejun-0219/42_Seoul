/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:37:17 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/19 21:24:54 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strlen(char *str, char c, int str_in)
{
	int	len;

	len = 0;
	while (str[str_in] != '\0')
	{
		if (str[str_in] == c)
			return (len);
		len++;
		str_in++;
	}
	return (len);
}

char	*ft_strdup5(char *str, int str_len)
{
	char	*newsrc;
	int		i;

	i = 0;
	newsrc = (char *) malloc (sizeof (char) * (str_len + 1));
	if (str_len == 0 || !newsrc)
		return (0);
	while (i < str_len)
	{
		newsrc[i] = str[i];
		i++;
	}
	newsrc[i] = '\0';
	return (newsrc);
}

int	get_count(char const *s, char c)
{
	int	count;
	int	len;
	int	flag;

	count = 0;
	flag = 0;
	len = ft_strlen(s);
	while (len--)
	{
		if (s[len] == c)
			flag = 0;
		else if (s[len] != c && !flag)
		{
			flag = 1;
			count++;
		}
	}
	return (count);
}

int	null_check(char **res, int res_in)
{
	if (!res[res_in])
	{
		while (res_in)
		{
			free(res[res_in--]);
		}
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		str_in;
	int		res_in;
	int		total_in;
	int		count;

	count = get_count((char *)s, c);
	result = (char **) malloc (sizeof(char *) * (count + 1));
	if (!result)
		return (0);
	result[count] = 0;
	str_in = 0;
	res_in = 0;
	while (res_in < count && s[str_in])
	{
		while (s[str_in] == c)
			str_in++;
		total_in = count_strlen((char *)s, c, str_in);
		result[res_in] = ft_strdup5((char *)s + str_in, total_in);
		if (null_check(result, res_in))
			break ;
		str_in += total_in;
		res_in++;
	}
	return (result);
}
