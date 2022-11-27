/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_ap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:03:59 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/25 23:46:17 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_ap(void *p, size_t *word)
{
	unsigned long	add;

	add = (unsigned long)p;
	ft_putstr_ap("0x", word);
	ft_putbase_ap(add, word, "0123456789abcdef");
}
