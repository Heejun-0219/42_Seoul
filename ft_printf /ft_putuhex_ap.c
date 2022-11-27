/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdhex_ap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 08:01:12 by heejunki          #+#    #+#             */
/*   Updated: 2022/11/20 08:02:31 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuhex_ap(unsigned int val, size_t *word)
{
	ft_putbase_ap(val, word, "0123456789ABCDEF");
}
