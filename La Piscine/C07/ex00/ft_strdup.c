/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:54:45 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/17 11:22:53 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
