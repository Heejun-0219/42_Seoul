/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:33:01 by prossi            #+#    #+#             */
/*   Updated: 2023/05/13 23:40:09 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horizontalwall(t_game *game)
{
	int	width;
	int	height;

	width = game->widthmap;
	height = 0;
	while (height < width)
	{
		if (game->map[0][height] == '0' \
		|| game->map[game->heightmap - 1][height] == '0')
			return (0);
		height++;
	}
	return (1);
}

int	verticalwall(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1' \
		&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

void	if_walls(t_game *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		ft_putstr_fd("Error\nThis map is missing the walls\n", 1);
		freegame(game);
	}
}

void	count_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_putstr_fd("Error\nThis map has invalid characters\n", 1);
		ft_putstr_fd("Valid characters are 0, 1, P, E, C\n", 1);
		freegame(game);
	}
	if (game->map[height][width] == 'C')
			game->itemcount++;
	if (game->map[height][width] == 'P')
	{
		game->x_axis = width;
		game->y_axis = height;
		game->playercount++;
	}
	if (game->map[height][width] == 'E')
			game->exitcount++;
}

void	character_valid(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->itemcount >= 1
			&& game->exitcount == 1))
	{
		ft_putstr_fd("Error\nThis map is missing the player, \
			exit or collectable\n", 1);
		freegame(game);
	}
}
