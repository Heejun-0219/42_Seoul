/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 07:53:42 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/17 12:01:10 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*newsrc;
	int		src_len;
	int		i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	newsrc = (char *) malloc (sizeof (char) * (src_len + 1));
	if (!newsrc)
		return (0);
	while (src[i])
	{
		newsrc[i] = src[i];
		i++;
	}
	newsrc[i] = '\0';
	return (newsrc);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*p;
	int			i;

	p = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (! p)
		return (0);
	i = 0;
	while (i < ac)
	{
		p[i].str = av[i];
		p[i].size = ft_strlen(av[i]);
		p[i].copy = ft_strdup(av[i]);
		++i;
	}
	p[ac].str = 0;
	return (p);
}
