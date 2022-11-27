/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_description_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 00:42:32 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/27 13:50:26 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	description_check(char format, va_list ap, size_t *word)
{
	if (format == '%')
		ft_putchar_ap(format, word);
	else if (format == 'c')
		ft_putchar_ap(va_arg(ap, int), word);
	else if (format == 's')
		ft_putstr_ap(va_arg(ap, void *), word);
	else if (format == 'p')
		ft_putptr_ap(va_arg(ap, void *), word);
	else if (format == 'd' || format == 'i')
		ft_putdigit_ap(va_arg(ap, int), word);
	else if (format == 'u')
		ft_putunsdigit_ap(va_arg(ap, unsigned int), word);
	else if (format == 'x')
		ft_puthex_ap(va_arg(ap, unsigned int), word);
	else if (format == 'X')
		ft_putuhex_ap(va_arg(ap, unsigned int), word);
}
