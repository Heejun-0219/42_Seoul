/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:49:02 by prossi            #+#    #+#             */
/*   Updated: 2023/05/18 20:30:47 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	freegame(t_game *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_game));
	read_map(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * RATIO),
			(game.heightmap * RATIO), "so_long");
	input_images(&game);
	map_setting(&game);
	mlx_key_hook(game.winpointer, player_control, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
	freegame(&game);
	return (0);
}
