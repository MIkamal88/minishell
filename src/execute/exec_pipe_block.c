/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:36:43 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/09 16:36:43 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	exec_child(t_mini *minishell, t_cmd *tmp)
{
	t_cmd	*ptr;

	ptr = minishell->cmd;
	dup2_close_fds(ptr);
	if (is_builtin(ptr->exec[0]))
		exec_builtin_child(minishell);
	else
	{
		exec_cmd_child_sig();
		execve(ptr->exec_path, ptr->exec, ptr->envp);
		exit_errno(ptr->exec[0], errno);
	}
	if (minishell->env)
		clear_env(minishell);
	if (minishell->parser)
		clear_parser(minishell);
	if (tmp)
		clear_cmd(&tmp);
	rl_clear_history();
	free(minishell);
	ft_error("", EXIT, g_exit_code);
}

void	exec_cmd(t_mini *minishell)
{
	t_cmd	*cmd;
	pid_t	pid[MAX_PID];
	int		id;

	id = -1;
	cmd = minishell->cmd;
	ft_memset(pid, 0, MAX_PID);
	cmd->exec_path = fetch_path(cmd, minishell->env);
	if (cmd->fd_in == -1 || cmd->fd_out == -1)
		exit_errno(cmd->errfile, cmd->errnb);
	else if (cmd->exec_path)
	{
		pid[++id] = fork();
		if (pid[id] == -1)
			ft_error(NULL, EXIT, 11);
		if (pid[id] == 0)
			exec_child(minishell, NULL);
	}
	close_fd(cmd, BOTH);
	wait_all(pid, id);
}

void	exec_pipe_block(t_mini *minishell)
{
	t_cmd	**ptr;
	t_cmd	*tmp;
	pid_t	pid[MAX_PID];
	int		id;

	id = -1;
	ptr = &minishell->cmd;
	tmp = minishell->cmd;
	while (*ptr)
	{
		setup_cmd(minishell, ptr);
		if ((*ptr)->fd_in == -1 || (*ptr)->fd_out == -1)
			exit_errno((*ptr)->errfile, (*ptr)->errnb);
		else if ((*ptr)->exec_path && is_forked(minishell))
		{
			pid[++id] = fork();
			if (pid[id] == -1)
				ft_error(NULL, EXIT, 11);
			if (pid[id] == 0)
				exec_child(minishell, tmp);
		}
		close_fd(*ptr, BOTH);
		*ptr = (*ptr)->next;
	}
	wait_all(pid, id);
}
