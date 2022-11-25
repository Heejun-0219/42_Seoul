/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:10:04 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/11 10:24:18 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	index;

	dest_len = 0;
	while (dest[dest_len])
		++dest_len;
	src_len = 0;
	index = dest_len;
	while (src[src_len] && dest_len + src_len + 1 < size)
		dest[index++] = src[src_len++];
	while (src[src_len])
		++src_len;
	dest[index] = '\0';
	if (size <= dest_len)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
