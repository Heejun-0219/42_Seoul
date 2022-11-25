/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:57:46 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/05 07:21:56 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_node(char *arr, int max)
{
	int	i;

	i = 0;
	while (i < max)
		write(1, &(arr[i++]), 1);
	if ((arr[0] - '0') + max != 10)
		write(1, ", ", 2);
}

void	dfs(int num, int depth, int max, char *arr)
{
	if (depth == max)
	{
		print_node(arr, max);
		return ;
	}
	while (num < 10)
	{
		arr[depth] = num + '0';
		dfs(++num, depth + 1, max, arr);
	}
}

void	ft_print_combn(int n)
{
	char	arr[9];

	if (0 < n && n < 10)
	{
		dfs(0, 0, n, arr);
	}
}
