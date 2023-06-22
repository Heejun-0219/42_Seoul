/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:25:31 by tnam              #+#    #+#             */
/*   Updated: 2023/05/04 23:30:33 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	first_cmd(t_pipe *var)
{
	var->in_fd = open(var->argv[1], O_RDONLY);
	if (var->in_fd == ERROR)
		ft_error();
	if (dup2(var->in_fd, STDIN_FILENO) == ERROR)
		ft_error();
	if (dup2(var->pipe_fd[OUT], STDOUT_FILENO) == ERROR)
		ft_error();
	if (close(var->in_fd) == ERROR)
		ft_error();
	if (close(var->pipe_fd[IN]) == ERROR)
		ft_error();
	if (close(var->pipe_fd[OUT]) == ERROR)
		ft_error();
	if (execve(var->cmd_path, var->cmd, var->envp) == ERROR)
		ft_error();
}

void	middle_cmd(t_pipe *var)
{
	if (dup2(var->pre_fd, STDIN_FILENO) == ERROR)
		ft_error();
	if (dup2(var->pipe_fd[OUT], STDOUT_FILENO) == ERROR)
		ft_error();
	if (close(var->pre_fd) == ERROR)
		ft_error();
	if (close(var->pipe_fd[IN]) == ERROR)
		ft_error();
	if (close(var->pipe_fd[OUT]) == ERROR)
		ft_error();
	if (execve(var->cmd_path, var->cmd, var->envp) == ERROR)
		ft_error();
}

void	last_cmd(t_pipe *var)
{
	var->out_fd = open(var->argv[var->argc - 1], O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (var->out_fd == ERROR)
		ft_error();
	if (dup2(var->pre_fd, STDIN_FILENO) == ERROR)
		ft_error();
	if (dup2(var->out_fd, STDOUT_FILENO) == ERROR)
		ft_error();
	if (close(var->pre_fd) == ERROR)
		ft_error();
	if (close(var->out_fd) == ERROR)
		ft_error();
	if (execve(var->cmd_path, var->cmd, var->envp) == ERROR)
		ft_error();
}

void	child(t_pipe *var)
{
	get_path_c(var);
	check_other(var);
	if (var->here_doc)
	{
		if (var->index_c == 3)
			hd_first_cmd(var);
		else
			hd_last_cmd(var);
	}
	if (var->index_c == 2)
		first_cmd(var);
	else if (var->index_c == var->argc - 2)
		last_cmd(var);
	else
		middle_cmd(var);
}
