/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:19:34 by heejunki          #+#    #+#             */
/*   Updated: 2022/12/19 16:13:19 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_read(int fd, char **backup)
{
	char	*buf;
	char	*tmp;
	ssize_t	read_size;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size == -1)
	{
		free(buf);
		return (-1);
	}
	buf[read_size] = '\0';
	tmp = *backup;
	*backup = ft_strjoin(*backup, buf);
	free(tmp);
	free(buf);
	if (!(*backup))
		return (-1);
	return (read_size);
}

char	*eof(char **backup)
{
	char	*str;

	if (ft_strlen(*backup) == 0)
	{
		free(*backup);
		*backup = 0;
		return (0);
	}
	else
	{
		str = *backup;
		*backup = 0;
		return (str);
	}
}

char	*ft_getline(char *tmp)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = 0;
	i = -1;
	while (tmp[len] != '\n')
		len++;
	if (tmp[len] == '\n')
		len++;
	if (len == 0)
		return (0);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
	{
		free(tmp);
		return (0);
	}
	while (++i < len)
		str[i] = tmp[i];
	str[i] = '\0';
	return (str);
}

char	*return_line(char **backup)
{
	char	*tmp;
	char	*str;

	tmp = ft_strdup(*backup);
	free(*backup);
	*backup = 0;
	if (!tmp)
		return (0);
	str = ft_getline(tmp);
	if (!str)
		return (0);
	*backup = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	if (!(*backup))
	{
		free(str);
		return (0);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	ssize_t		read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (!(ft_strchr(backup[fd], '\n')))
	{
		read_size = ft_read(fd, &backup[fd]);
		if (read_size == -1)
		{
			free(backup[fd]);
			backup[fd] = 0;
			return (0);
		}
		if (read_size == 0)
			return (eof(&backup[fd]));
	}
	return (return_line(&backup[fd]));
}
