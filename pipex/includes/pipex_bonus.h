/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:24:54 by tnam              #+#    #+#             */
/*   Updated: 2023/05/04 23:30:52 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define CHILD 0
# define IN 0
# define SUCCESS 0
# define OUT 1
# define ERROR -1
# define NONE -1

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include <stdio.h>

typedef struct s_var
{
	int		argc;
	char	**argv;
	char	**envp;
	int		here_doc;
	char	*limiter;
	int		prev_pipe_fd;
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];
	pid_t	pid;
	char	**paths;
	char	**cmd;
	char	*cmd_path;
	int		cmd_i;
	int		cmd_count;
	int		cmd_isin;
}			t_var;

typedef struct s_parser
{
	int		i;
	int		start;
	int		end;
	int		str_i;
	int		str_count;
	int		str_len;
	char	*cmd;
	char	**result;
}			t_parser;

void	ft_child(t_var *var);
void	ft_parent(t_var *var);
void	ft_find_cmd_path(t_var *var);
void	ft_make_cmd_if_awk_sed(t_var *var);
void	ft_error(void);
void	ft_here_doc_first_cmd(t_var *var);
void	ft_here_doc_last_cmd(t_var *var);
#endif