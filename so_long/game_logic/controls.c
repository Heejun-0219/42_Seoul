/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:24 by prossi            #+#    #+#             */
/*   Updated: 2022/12/12 20:44:37 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ESC 53
#define W 13
#define S 1
#define A 0
#define D 2
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

static int	right_move(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("\nYou Have Won, Congrats!\n");
		freegame(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

void print_moving(t_game *game){
	printf("the current number of movements: %i\n", game->counter);
	printf("Item Remaining: %i\n", game->collectables);
}

static int	keyboard_w_s(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == W || movement == UP)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == S || movement == DOWN)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	print_moving(game);
	return (1);
}

static int	keyboard_a_d(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == A || movement == LEFT)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == D || movement == RIGHT)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	print_moving(game);
	return (1);
}

int	player_control(int command, t_game *game)
{
	int	works;

	if (command == ESC)
		freegame(game);
	if (command == W || command == UP)
		works = keyboard_w_s(game, command);
	if (command == S || command == DOWN)
		works = keyboard_w_s(game, command);
	if (command == A || command == LEFT)
		works = keyboard_a_d(game, command);
	if (command == D || command == RIGHT)
		works = keyboard_a_d(game, command);
	if (works)
		map_setting(game);
	return (1);
}
