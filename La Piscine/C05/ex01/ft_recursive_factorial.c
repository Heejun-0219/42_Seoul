/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:13:26 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/15 21:22:48 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	else if (nb > 0)
		return (nb * ft_recursive_factorial(nb - 1));
	else
		return (0);
}
