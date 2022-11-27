/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:04:05 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/27 13:50:13 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//ap == arguments pointer
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	word;

	if (!format)
		return (0);
	word = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			description_check((char)*format, ap, &word);
		}
		else
			ft_putchar_ap(*format, &word);
		format++;
	}
	va_end(ap);
	return ((int)word);
}
// char ch = (char) va_arg(ap, int);
// va_start, va_arg, va_copy, va_end

#include <stdio.h>
int main(){
	printf("%s\n", "abcdefghijk");
	ft_printf("%s\n", "abcdefghijk");
	return 0;
}