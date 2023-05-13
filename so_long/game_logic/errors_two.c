/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:24:32 by heejunki          #+#    #+#             */
/*   Updated: 2023/05/13 23:40:27 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**visited(t_game *game)
{
	int	**visited;
	int	i;
	int	j;

	i = 0;
	visited = (int **)malloc(sizeof(int *) * game->heightmap);
	while (i < game->heightmap)
	{
		j = 0;
		visited[i] = (int *)malloc(sizeof(int) * game->widthmap);
		while (j < game->widthmap)
		{
			visited[i][j] = '0';
			j++;
		}
		i++;
	}
	return (visited);
}

void	init_check(t_game *game, t_check *check)
{
	check->visited = visited(game);
	check->y = game->heightmap;
	check->x = game->widthmap;
	check->itemcount = game->itemcount;
	check->vaild = 0;
}

void	dfs(t_game *game, t_check *check, int y, int x)
{
	if (y < 0 || y >= check->y || x < 0 || x >= check->x)
		return ;
	if (check->visited[y][x] == '1')
		return ;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'E')
	{
		check->vaild = 1;
		return ;
	}
	if (game->map[y][x] == 'C')
		check->itemcount--;
	check->visited[y][x] = '1';
	dfs(game, check, y + 1, x);
	dfs(game, check, y - 1, x);
	dfs(game, check, y, x + 1);
	dfs(game, check, y, x - 1);
}

void	if_road(t_game *game)
{
	t_check	check;
	int		i;

	init_check(game, &check);
	dfs(game, &check, game->y_axis, game->x_axis);
	if (!check.vaild || check.itemcount > 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("No vaild Road in map.\n", 1);
		freegame(game);
	}
	i = 0;
	while (i < game->heightmap)
		free(check.visited[i++]);
	free(check.visited);
}

void	check_errors(t_game *game)
{
	if_walls(game);
	character_valid(game);
	if_road(game);
}
