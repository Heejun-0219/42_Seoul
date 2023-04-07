/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:33:01 by prossi            #+#    #+#             */
/*   Updated: 2022/12/12 20:46:47 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontalwall(t_complete *game)
{
	int	width;
	int	height;

	width = game->widthmap;
	height = 0;
	while (height < width)
	{
		if (game->map[0][height] == '0' || game->map[game->heightmap - 1][height] == '0')
			return (0);
		height++;
	}
	return (1);
}

static int	verticalwall(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1' && game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	if_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;


	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\nThis map is missing the walls\n");
		exit_point(game);
	}
}

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\nError Here!%c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
			game->columncount++;
	if (game->map[height][width] == 'P')
			game->playercount++;
	if (game->map[height][width] == 'E')
			game->exitcount++;
}

void	character_valid(t_complete *game)
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
	if (!(game->playercount == 1 && game->columncount >= 1
			&& game->exitcount == 1))
	{
		printf("\nError\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		exit_point(game);
	}
}

int **visited(t_complete *game){
	int **visited;
	int i;
	int j;

	i = 0;
	visited = (int **)malloc(sizeof(int *) * game->heightmap);
	while (i < game->heightmap){
		j = 0;
		visited[i] = (int *)malloc(sizeof(int) * game->widthmap);
		while (j < game->widthmap){
			visited[i][j] = '0';
			j++;
		}
		i++;
	}
	return (visited);
}

void init_check(t_complete *game, t_check *check){
	check->visited = visited(game);
	check->y = game->heightmap;
	check->x = game->widthmap;
	check->columncount = game->columncount;
	check->vaild = 0;
	check->count = 0;
}

void dfs(t_complete *game, t_check *check, int y, int x){
	check->count++;
	if (y < 0 || y >= check->y || x < 0 || x >= check->x)
		return ;
	if (check->visited[y][x] == '1')
		return ;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'E'){
		check->vaild = 1;
		return ;
	}
	if (game->map[y][x] == 'C')
		check->columncount--;
	check->visited[y][x] = '1';
	dfs(game, check, y + 1, x);
	dfs(game, check, y - 1, x);
	dfs(game, check, y, x + 1);
	dfs(game, check, y, x - 1);
}

void if_road(t_complete *game){
	t_check check;

	init_check(game, &check);
	dfs(game, &check, game->y_axis, game->x_axis);
	if (!check.vaild || check.columncount > 0){
		// current player position
		printf("\n\n%d %d %d %d %d %d %d \n\n", check.count,check.x, check.y, check.columncount, check.vaild, game->x_axis, game->y_axis);
		printf("\nError\n");
		printf("No vaild Road in map.\n");
		exit_point(game);
	}
}

void	check_errors(t_complete *game)
{
	if_walls(game);
	character_valid(game);
	if_road(game);
	// Remaining errors Left

}
