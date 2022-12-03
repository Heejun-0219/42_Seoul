/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:19:34 by heejunki          #+#    #+#             */
/*   Updated: 2022/12/03 13:24:02 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fd_read_line(int fd, char *p)
{
	char	*buffer;
	ssize_t	check_end;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	check_end = 1;
	while (!ft_strchr(p, '\n') && check_end != 0)
	{
		check_end = read(fd, buffer, BUFFER_SIZE);
		if (check_end == -1)
		{
			free(buffer);
			free(p);
			return (NULL);
		}
		buffer[check_end] = '\0';
		p = ft_strjoin(p, buffer);
	}
	free(buffer);
	return (p);
}

char	*fd_get_line(char *p)
{
	char	*tmp;
	int		len;

	if (!*p)
		return (NULL);
	len = 0;
	while (p[len] && p[len] != '\n')
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 2));
	if (!tmp)
		return (NULL);
	len = 0;
	while (p[len] && p[len] != '\n')
	{
		tmp[len] = p[len];
		len++;
	}
	if (p[len] == '\n')
	{
		tmp[len] = p[len];
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}

char	*fd_save_line(char *p)
{
	char	*tmp;
	int		index;
	int		i;

	index = 0;
	while (p[index] && p[index] != '\n')
		index++;
	if (!p[index])
	{
		free(p);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(p) - index + 1));
	if (!tmp)
		return (NULL);
	index++;
	i = 0;
	while (p[index])
	{
		tmp[i++] = p[index++];
	}
	tmp[i] = '\0';
	free(p);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	p = fd_read_line(fd, p);
	if (!p)
		return (NULL);
	buffer = fd_get_line(p);
	p = fd_save_line(p);
	return (buffer);
}
