/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2023/05/19 00:41:48 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

# define RATIO 50

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
	int	vaild;
}	t_check;

int		is_valid_file(const char *path);
void	ft_putnbr_fd(int n, int fd);
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
void	print_moving(t_game *game);
int		horizontalwall(t_game *game);
int		verticalwall(t_game *game);
void	if_walls(t_game *game);
void	count_checker(t_game *game, int height, int width);
void	character_valid(t_game *game);
int		moving_util(t_game *game, int i, int j, int *k);
int		moving_util_two(t_game *game, int i, int j, int *k);
int		right_move(t_game *game, int i, int j);
int		width_of_map(char *string);

#endif
