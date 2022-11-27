/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:52:32 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/25 23:56:06 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	description_check(char format, va_list ap, size_t *word);
void	ft_putchar_ap(char c, size_t *word);
void	ft_putstr_ap(char *s, size_t *word);
void	ft_putdigit_ap(long val, size_t *word);
void	ft_putunsdigit_ap(unsigned int val, size_t *word);
void	ft_putptr_ap(void *p, size_t *word);
void	ft_puthex_ap(unsigned int val, size_t *word);
void	ft_putuhex_ap(unsigned int val, size_t *word);
void	ft_putbase_ap(unsigned long val, size_t *word, char *base);
int		integer_len(int ln);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
#endif