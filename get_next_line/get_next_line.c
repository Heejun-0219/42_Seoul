/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:19:34 by heejunki          #+#    #+#             */
/*   Updated: 2022/12/01 14:19:37 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fd_read_line(int fd, char *p)
{
	char	*buffer;
	ssize_t	check_end;

	buffer = (char *)malloc(sizeof(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	check_end = 1;
	while (!ft_strrchr(p, '\n') && check_end == 1)
	{
		check_end = read(fd, buffer, BUFFER_SIZE);
		if (check_end == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[check_end] = '\n';
		p = ft_strjoin(p, buffer);
	}
	free(buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		buffer[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	p = fd_read_line(fd, p);
	if (!p)
		return (NULL);

	return (buffer);
}
