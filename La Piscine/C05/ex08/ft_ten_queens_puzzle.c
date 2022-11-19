/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:35:16 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/16 03:50:03 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_pos(int puzzle[10], int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (puzzle[i] == puzzle[pos])
			return (0);
		else if (pos - puzzle[pos] == i - puzzle[i])
			return (0);
		else if (pos + puzzle[pos] == i + puzzle[i])
			return (0);
		++i;
	}
	return (1);
}

void	find_puzzle(int puzzle[10], int pos, int *count)
{
	int	val;
	int	i;

	i = 0;
	if (pos == 10)
	{
		while (i < 10)
			write(1, &puzzle[i++], 1);
		write(1, "\n", 1);
		(*count)++;
		return ;
	}
	val = 0;
	while (val < 10)
	{
		puzzle[pos] = val + '0';
		if (check_pos(puzzle, pos))
			find_puzzle(puzzle, pos + 1, count);
		++val;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	puzzle[10];
	int	count;

	find_puzzle(puzzle, 0, &count);
	return (count);
}
