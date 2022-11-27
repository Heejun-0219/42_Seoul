/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_ap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 07:59:24 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/25 23:46:40 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase_ap(unsigned long val, size_t *word, char *base)
{
	char	c;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (val < base_len)
	{
		c = base[val];
		ft_putchar_ap(c, word);
	}
	else
	{
		ft_putbase_ap(val / base_len, word, base);
		ft_putbase_ap(val % base_len, word, base);
	}
}
