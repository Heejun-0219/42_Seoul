/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_find_cmd_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:25 by tnam              #+#    #+#             */
/*   Updated: 2023/05/04 23:30:34 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	not_cmd(t_pipe *var)
{
	write(1, "command not found: ", 19);
	write(1, var->cmd[0], ft_strlen(var->cmd[0]));
	write(1, "\n", 1);
	exit(127);
}

int	abs_path(t_pipe *var)
{
	if (access(var->cmd[0], X_OK) == SUCCESS)
	{
		var->cmd_path = var->cmd[0];
		return (1);
	}
	return (0);
}

char	*make_path(t_pipe *var, char *path)
{
	char	*result;
	char	*temp;

	temp = ft_strjoin(path, "/");
	if (temp == NULL)
		exit(EXIT_FAILURE);
	result = ft_strjoin(temp, var->cmd[0]);
	if (result == NULL)
	{
		free(temp);
		exit(EXIT_FAILURE);
	}
	free(temp);
	return (result);
}

void	get_path_c(t_pipe *var)
{
	size_t	i;
	char	*cmd_path;

	var->cmd = ft_split(var->argv[var->index_c], ' ');
	if (var->cmd == NULL)
		exit(EXIT_FAILURE);
	if (abs_path(var))
		return ;
	i = 0;
	while (var->paths[i])
	{
		cmd_path = make_path(var, var->paths[i]);
		if (access(cmd_path, X_OK) == SUCCESS)
		{
			var->cmd_path = cmd_path;
			var->possible_c = 1;
			break ;
		}
		free(cmd_path);
		i++;
	}
	if (var->possible_c == 0)
		not_cmd(var);
}
