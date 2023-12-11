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

static void	dup2_close_fds(t_cmd *cmd)
{
	if (cmd->fd_in > 2)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->fd_out > 2)
		dup2(cmd->fd_out, STDOUT_FILENO);
	close_fds(cmd);
}

static void	exec_child(t_mini *minishell)
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
	clear(minishell);
	ft_error("", EXIT, g_exit_code);
}

static void	wait_all(int pid[MAX_PID], int id)
{
	int		max_id;
	int		wstatus;

	if (id == -1)
		return ;
	max_id = id;
	id = -1;
	wstatus = 0;
	while (++id <= max_id)
		waitpid(pid[id], &wstatus, 0);
	if (WIFEXITED(wstatus))
		g_exit_code = WEXITSTATUS(wstatus);
}

void	exec_pipe_block(t_mini *minishell)
{
	t_cmd	**ptr;
	pid_t	pid[MAX_PID];
	int		id;

	id = -1;
	ptr = &minishell->cmd;
	while (*ptr)
	{
		exec_cmd_parent_sig();
		(*ptr)->exec_path = fetch_path(*ptr, minishell->env);
		(*ptr)->envp = create_envp(minishell->env);
		if ((*ptr)->fd_in == -1 || (*ptr)->fd_out == -1)
			exit_errno((*ptr)->errfile, (*ptr)->errnb);
		else if ((*ptr)->exec_path && is_forked(minishell))
		{
			pid[++id] = fork();
			if (pid[id] == -1)
				ft_error(NULL, EXIT, 11);
			if (pid[id] == 0)
				exec_child(minishell);
		}
		close_fd(*ptr, BOTH);
		*ptr = (*ptr)->next;
	}
	wait_all(pid, id);
}
