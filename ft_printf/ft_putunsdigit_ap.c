/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsdigit_ap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:30:22 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/20 04:03:32 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsdigit_ap(unsigned int val, size_t *word)
{
	char	c;

	if (val <= 9)
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
