/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:38:02 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/08 22:01:14 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	EXEC_LINE
**	---------
**	DESCRIPTION
**	The main workflow for the execution of all commands passed by the user through
**	the prompt line. It first opens all the pipes, and then it reads and applies
**	the redirects and heredocs (since they have precedence over pipes). Lastly, 
**	it executes the commands by priority indentation.
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	execute_with_pipes(t_mini *minishell, t_cmd *cmd, int prev_pipe[])
{
	if (cmd->endpoint == PIPE)
	{
		if (pipe(cmd->fd_pipe) == -1)
		{
			perror("Pipe creation failed");
			exit(EXIT_FAILURE);
		}
		execute_with_pipe(cmd, prev_pipe[0], cmd->fd_pipe[1], minishell);
		close(cmd->fd_pipe[1]);
		prev_pipe[0] = cmd->fd_pipe[0];
		prev_pipe[1] = cmd->fd_pipe[1];
		cmd->fd_in = prev_pipe[0];
	}
	else
		execute_with_pipe(cmd, prev_pipe[0], cmd->fd_out, minishell);
}

void	exec_cmds(t_mini *minishell)
{
	t_cmd	*cmd;
	int		prev_pipe[2];

	cmd = minishell->cmd;
	while (cmd)
	{
		execute_with_pipes(minishell, cmd, prev_pipe);
		cmd = cmd->next;
	}
	if (prev_pipe[0] != 0)
		close(prev_pipe[0]);
}

void	exec_line(t_mini *minishell)
{
	setup_envp_pipes(minishell);
	if (!define_redirects(minishell))
		return ;
	exec_cmds(minishell);
}
