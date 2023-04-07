/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2022/12/12 20:41:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

# define RATIO 48

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		itemcount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_game;

typedef struct s_check
{
	int	y;
	int	x;
	int	itemcount;
	int	**visited;
	int vaild;
	int count; // dfs
}	t_check;

int		freegame(t_game *game);
int		read_map(t_game *game, char **argv);
int		player_control(int command, t_game *game);
void	map_setting(t_game *game);
void	input_images(t_game *game);
void	check_errors(t_game *game);
void	if_road(t_game *game);
void	dfs(t_game *game, t_check *check, int y, int x);
void	init_check(t_game *game, t_check *check);
int		**visited(t_game *game);

#endif
