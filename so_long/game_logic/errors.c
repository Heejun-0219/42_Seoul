/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:33:01 by prossi            #+#    #+#             */
/*   Updated: 2023/04/07 18:44:28 by heejunki         ###   ########.fr       */
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
		printf("\nError\nThis map is missing the walls\n\n");
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
		printf("\nError Here!%c\n", game->map[height][width]);
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
		printf("\nError\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		freegame(game);
	}
}
