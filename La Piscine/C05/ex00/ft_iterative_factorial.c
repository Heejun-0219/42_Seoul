/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:10:52 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/15 21:37:23 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = 1;
	if (nb == 0)
		return (1);
	else if (nb > 0)
	{
		while (nb != 0)
		{
			i *= nb;
			nb -= 1;
		}
		return (i);
	}
	else
		return (0);
}
