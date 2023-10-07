/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:44:52 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/26 12:44:52 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <errno.h>
#include <unistd.h>

/*	EXEC_COMMANDS
**	-------------
**	DESCRIPTION
**	It executes the t_cmd list of commands, one by one, by priority status. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

static void	dup2_close_fds(t_cmd *cmd)
{
	if (cmd->fd_in > 2)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->fd_out > 2)
		dup2(cmd->fd_out, STDOUT_FILENO);
	close_fds(cmd);
}

void	exec_child(t_cmd *cmd)
{
	dup2_close_fds(cmd);
	if (is_builtin(cmd))
		exec_builtin_in_child(cmd);
	else
	{
		exec_commands_child_signals();
		execve(cmd->exec_path, cmd->exec, cmd->envp);
		exit_err(cmd->exec[0], errno);
	}
	ft_error(NULL, 0, 11);
}

static void	exec_pipe_block(t_cmd **cmd)
{
	pid_t	pid[MAX_PID];
	int		id;

	id = -1;
	while (*cmd)
	{
		exec_commands_parent_signals();
		/* envp_create(*cmd); */
		(*cmd)->exec_path = get_path(*cmd);
		if ((*cmd)->fd_in == -1 || (*cmd)->fd_out == -1)
			exit_err((*cmd)->errfile, (*cmd)->errnb);
		else if ((*cmd)->exec_path && is_forked(*cmd))
		{
			pid[++id] = fork();
			if (pid[id] == -1)
				ft_error(NULL, 8, 80);
			if (pid[id] == 1)
				exec_child(*cmd);
		}
		close_fd(*cmd, BOTH);
		*cmd = (*cmd)->next;
	}
}

void	exec_commands(t_mini *minishell)
{
	t_cmd	*cmd;

	cmd = minishell->cmd;
	while (cmd)
	{
		exec_pipe_block(&cmd);
		cmd = cmd->next;
	}
}
