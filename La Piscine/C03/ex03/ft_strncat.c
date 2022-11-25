/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:27:33 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/11 09:47:37 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int		i;
	int		j;

	i = 0;
	while (dest[i])
		++i;
	j = 0;
	while (nb && src[j])
	{
		dest[i] = src[j];
		++i;
		--nb;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}
