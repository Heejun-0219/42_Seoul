/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit_ap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:09:23 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/20 01:19:55 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdigit_ap(long val, size_t *word)
{
	char	c;

	if (val < 0)
	{
		val *= -1;
		ft_putchar_ap('-', word);
		ft_putdigit_ap(val, word);
	}
	else if (val <= 9)
	{
		c = val + '0';
		ft_putchar_ap(c, word);
	}
	else
	{
		ft_putdigit_ap(val / 10, word);
		ft_putdigit_ap(val % 10, word);
	}
}
