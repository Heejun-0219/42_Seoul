/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:34:01 by prossi            #+#    #+#             */
/*   Updated: 2023/05/19 00:42:02 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_game *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n <= 9)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

int	is_valid_file(const char *path)
{
	struct stat	st;

	if (stat(path, &st) == 0 && S_ISREG(st.st_mode))
	{
		return (1);
	}
	return (0);
}

int	read_map(t_game *game, char **argv)
{
	char	*readmap;

	if (!is_valid_file(argv[1]) || !strstr(argv[1], ".ber"))
		return (0);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close(game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
