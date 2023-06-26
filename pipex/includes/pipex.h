/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:24:54 by tnam              #+#    #+#             */
/*   Updated: 2023/05/04 23:30:53 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define CHILD 0
# define IN 0
# define SUCCESS 0
# define OUT 1
# define ERROR -1
# define NONE -1

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include <stdio.h>

typedef struct s_pipe
{
	int		argc;
	char	**argv;
	char	**envp;
	int		pre_fd;
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];
	pid_t	pid;
	char	**paths;
	char	**cmd;
	char	*cmd_path;
	int		index_c;
	int		count_c;
	int		possible_c;
}			t_pipe;

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

void	child(t_pipe *var);
void	parent(t_pipe *var);
void	get_path_c(t_pipe *var);
void	check_other(t_pipe *var);
void	ft_error(void);
int		abs_path(t_pipe *var);
void	copycmd(t_parser *p_var);
void	space(t_parser *p_var);
void	query(t_parser *p_var, char quote);
void	other_command(t_pipe *var, t_parser *p_var);
void	first_cmd(t_pipe *var);
void	middle_cmd(t_pipe *var);
void	last_cmd(t_pipe *var);
void	not_cmd(t_pipe *var);
char	*make_path(t_pipe *var, char *path);

#endif