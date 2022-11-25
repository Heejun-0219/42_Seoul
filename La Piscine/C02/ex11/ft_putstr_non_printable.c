/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:40:58 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/06 16:00:28 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned char	uch;
	char			*hex;

	hex = "0123456789abcdef";
	while (*str)
	{
		if (*str < 32 || *str == 127)
		{
			uch = *str;
			write(1, "\\", 1);
			write(1, &hex[uch / 16], 1);
			write(1, &hex[uch % 16], 1);
		}
		else
			write(1, str, 1);
		++str;
	}
}
