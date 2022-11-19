/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:49:54 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/17 10:16:19 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(char s1, char *s2)
{
	int	k;

	k = 0;
	while (s2[k] != '\0')
	{
		if (s1 == s2[k])
			return (1);
		k++;
	}
	return (0);
}

int	count_str(char *str, char *charset)
{
	int	flag;
	int	count;
	int	i;

	flag = 0;
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strcmp(str[i], charset) == 0 && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (ft_strcmp(str[i], charset) == 1)
			flag = 0;
		i++;
	}
	return (count);
}

int	count_strlen(char *str, char *charset, int str_in)
{
	int	len;

	len = 0;
	while (str[str_in] != '\0')
	{
		if (ft_strcmp(str[str_in], charset) == 1)
			return (len);
		len++;
		str_in++;
	}
	return (len);
}

char	*ft_strdup5(char *str, int str_len, int str_in)
{
	char	*newsrc;
	int		i;

	i = 0;
	newsrc = (char *) malloc (sizeof (char) * (str_len + 1));
	if (str_len == 0 || !newsrc)
		return (0);
	while (i < str_len)
		newsrc[i++] = str[str_in++];
	newsrc[i] = '\0';
	return (newsrc);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		count;
	int		str_in;
	int		res_in;
	int		total_in;

	str_in = 0;
	res_in = 0;
	count = count_str(str, charset);
	result = (char **) malloc (sizeof (char *) * (count + 1));
	if (result == 0)
		return (0);
	while (res_in < count && str[str_in] != '\0')
	{
		while (ft_strcmp(str[str_in], charset) != 0)
			str_in++;
		total_in = count_strlen(str, charset, str_in);
		result[res_in] = ft_strdup5(str, total_in, str_in);
		str_in += total_in;
		res_in++;
	}
	result[res_in] = 0;
	return (result);
}
