/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:24:09 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/13 07:19:37 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	src_size;

	src_size = 0;
	index = 0;
	while (src[src_size])
		src_size++;
	if (size == 0)
		return (src_size);
	while (size > index + 1 && src_size > index)
	{
		dest[index] = src[index];
		++index;
	}
	dest[index] = '\0';
	return (src_size);
}
