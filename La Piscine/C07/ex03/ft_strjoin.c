/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:32:41 by heejunmi          #+#    #+#             */
/*   Updated: 2022/10/19 07:47:40 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		k;

	i = ft_strlen(dest);
	k = 0;
	while (src[k] != '\0')
	{
		dest[i] = src[k];
		k++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	get_total_l(int size, char **strs, char *sep)
{
	int	i;
	int	count;
	int	sep_len;

	i = 0;
	count = 0;
	sep_len = ft_strlen(sep);
	if (size == 0)
		return (0);
	while (i < size - 1)
	{
		count += ft_strlen(strs[i]);
		count += sep_len;
		i++;
	}
	count += ft_strlen(strs[size - 1]);
	return (count);
}

void	strs_copy(int size, char **strs, char *sep, char *p)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		p = ft_strcat(p, strs[i++]);
		p = ft_strcat(p, sep);
	}
	p = ft_strcat(p, strs[size - 1]);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*p;
	int		total_len;

	total_len = get_total_l(size, strs, sep);
	if (size == 0)
	{
		p = (char *)malloc(1);
		p[0] = 0;
		return (p);
	}
	p = (char *) malloc (sizeof (char) * (total_len + 1));
	if (!p)
		return (0);
	p[0] = 0;
	strs_copy(size, strs, sep, p);
	p[total_len] = 0;
	return (p);
}
