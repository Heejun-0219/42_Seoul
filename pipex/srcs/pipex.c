/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:54:39 by tnam              #+#    #+#             */
/*   Updated: 2023/05/04 23:30:38 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_variables(t_var *var, int argc, char *argv[], char *envp[])
{
	size_t	i;
	char	*path;

	var->argc = argc;
	var->argv = argv;
	var->envp = envp;
	var->prev_pipe_fd = NONE;
	var->cmd = NULL;
	var->cmd_path = NULL;
	var->cmd_i = 2;
	var->cmd_count = argc - 3;
	var->cmd_isin = 0;
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = envp[i] + 5;
	var->paths = ft_split(path, ':');
	if (var->paths == NULL)
		exit(EXIT_FAILURE);
}

void	ft_exec_cmd(t_var *var)
{
	if (var->cmd_i != var->argc - 2)
		if (pipe(var->pipe_fd) == ERROR)
			ft_error();
	var->pid = fork();
	if (var->pid == ERROR)
		ft_error();
	else if (var->pid == CHILD)
		ft_child(var);
	else
		ft_parent(var);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_var	var;
	int		i;

	if (argc != 5)
		return (EXIT_FAILURE);
	ft_init_variables(&var, argc, argv, envp);
	while (var.cmd_i < argc - 1)
	{
		ft_exec_cmd(&var);
		var.cmd_i++;
	}
	i = 0;
	while (i++ < var.cmd_count)
	{
		if (wait(NULL) == ERROR)
			ft_error();
	}
	return (0);
}