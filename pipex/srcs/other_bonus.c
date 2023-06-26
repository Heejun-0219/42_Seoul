/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:31:38 by heejunki          #+#    #+#             */
/*   Updated: 2023/06/26 22:44:13 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	copycmd(t_parser *p_var)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * p_var->str_len + 1);
	if (str == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (p_var->start <= p_var->end)
	{
		str[i] = p_var->cmd[p_var->start];
		i++;
		p_var->start++;
	}
	str[i] = '\0';
	p_var->result[p_var->str_i++] = str;
}

void	space(t_parser *p_var)
{
	p_var->end = p_var->i - 1;
	p_var->str_len = (p_var->end - p_var->start) + 1;
	copycmd(p_var);
	while (p_var->cmd[p_var->start] == ' ')
		p_var->start++;
	p_var->i = p_var->start - 1;
}

void	query(t_parser *p_var, char quote)
{
	int		quote_end;

	p_var->start = p_var->i + 1;
	quote_end = p_var->start;
	while (!p_var->cmd[quote_end] || p_var->cmd[quote_end] != quote)
		quote_end++;
	p_var->end = quote_end - 1;
	p_var->str_len = (p_var->end - p_var->start) + 1;
	copycmd(p_var);
	p_var->start++;
	while (p_var->cmd[p_var->start] == ' ')
		p_var->start++;
	p_var->i = p_var->start - 1;
}

void	other_command(t_pipe *var, t_parser *p_var)
{
	p_var->result = (char **)malloc(sizeof(char *) * (p_var->str_count + 1));
	if (p_var->result == NULL)
		exit(EXIT_FAILURE);
	while (p_var->cmd[p_var->i])
	{
		if (p_var->cmd[p_var->i] == ' ')
			space(p_var);
		else if (p_var->cmd[p_var->i] == '\'' || p_var->cmd[p_var->i] == '"')
			query(p_var, p_var->cmd[p_var->i]);
		p_var->i++;
	}
	p_var->result[p_var->str_i] = NULL;
	var->cmd = p_var->result;
	p_var->result = NULL;
}

void	check_other(t_pipe *var)
{
	t_parser	p_var;
	int			i;

	if (ft_strncmp(var->cmd[0], "awk", 3) == 0
		|| ft_strncmp(var->cmd[0], "sed", 3) == 0)
	{
		free(var->cmd);
		var->cmd = NULL;
		p_var.i = 0;
		p_var.start = 0;
		p_var.end = 0;
		p_var.str_i = 0;
		p_var.str_count = 1;
		p_var.str_len = 0;
		p_var.cmd = var->argv[var->index_c];
		p_var.result = NULL;
		i = 0;
		while (p_var.cmd[i])
		{
			if (p_var.cmd[i] == ' ')
				p_var.str_count++;
			i++;
		}
		other_command(var, &p_var);
	}
}
