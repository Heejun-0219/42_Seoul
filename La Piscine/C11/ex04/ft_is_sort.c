/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:48:54 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/20 12:26:35 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sor_p;
	int	sor_n;

	i = 0;
	sor_p = 0;
	sor_n = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			++sor_p;
		else if (f(tab[i], tab[i + 1]) == 0)
		{
			++sor_p;
			++sor_n;
		}
		else
			++sor_n;
		++i;
	}
	if (i == sor_p || i == sor_n)
		return (1);
	else
		return (0);
}
