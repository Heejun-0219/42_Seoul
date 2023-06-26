/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:54:39 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:44:15 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	init_var(t_pipe *var, int argc, char *argv[], char *envp[])
{
	size_t	i;
	char	*path;

	var->argc = argc;
	var->argv = argv;
	var->envp = envp;
	var->here_doc = 0;
	var->limiter = NULL;
	var->pre_fd = NONE;
	var->cmd = NULL;
	var->cmd_path = NULL;
	var->index_c = 2;
	var->count_c = argc - 3;
	var->possible_c = 0;
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = envp[i] + 5;
	var->paths = ft_split(path, ':');
	if (var->paths == NULL)
		exit(EXIT_FAILURE);
}

void	hd_init(t_pipe *var)
{
	var->here_doc = 1;
	var->limiter = ft_strjoin(var->argv[2], "\n");
	if (var->limiter == NULL)
		exit(EXIT_FAILURE);
	var->index_c = 3;
	var->count_c = var->argc - 4;
}

void	exe_cmd(t_pipe *var)
{
	if (var->index_c != var->argc - 2)
		if (pipe(var->pipe_fd) == ERROR)
			ft_error();
	var->pid = fork();
	if (var->pid == ERROR)
		ft_error();
	else if (var->pid == CHILD)
		child(var);
	else
		parent(var);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	var;
	int		i;

	if (argc < 5)
		return (EXIT_FAILURE);
	init_var(&var, argc, argv, envp);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		hd_init(&var);
	while (var.index_c < argc - 1)
	{
		exe_cmd(&var);
		var.index_c++;
	}
	i = 0;
	while (i++ < var.count_c)
	{
		if (wait(NULL) == ERROR)
			ft_error();
	}
	if (var.here_doc)
	{
		if (unlink("temp") == ERROR)
			ft_error();
	}
	return (0);
}
