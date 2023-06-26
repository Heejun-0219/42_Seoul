/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:25:24 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:44:13 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parent(t_pipe *var)
{
	if (var->index_c != var->argc - 2)
	{
		if (close(var->pipe_fd[OUT]) == ERROR)
			ft_error();
	}
	if (var->pre_fd != NONE)
		if (close(var->pre_fd) == ERROR)
			ft_error();
	var->pre_fd = var->pipe_fd[IN];
}
