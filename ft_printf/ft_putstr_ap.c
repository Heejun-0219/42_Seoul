/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:06:49 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/20 02:03:08 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_ap(char *s, size_t *word)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar_ap(*s, word);
		s++;
	}
}
