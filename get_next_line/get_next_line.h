/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:22:20 by heejunki          #+#    #+#             */
/*   Updated: 2022/12/01 14:18:34 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
//# include <sys/types.h>
# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*ft_strrchr(const char *str, int c);
char	*ft_strjoin(char const	*s1, char const *s2);

#endif