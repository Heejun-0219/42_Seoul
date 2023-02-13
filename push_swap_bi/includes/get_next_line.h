/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:06:52 by jaewpark          #+#    #+#             */
/*   Updated: 2023/02/13 12:05:13 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "push_swap.h"
# define BUFFER_SIZE 10

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*free_strjoin(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		free_all(t_pushswap *t);
int			line_return(char **str, char **line, int idx, int read_size);
int			one_line(char **str, char **line, int idx);
int			get_next_line(int fd, char **line);
int			str_free(char **str);
int			find_nl(char *str);

#endif
