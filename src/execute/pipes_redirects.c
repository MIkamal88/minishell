/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:12:40 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/06 12:12:40 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	setup_envp_pipes
 *	----------------
 *	DESCRIPTION
 *	This function creates envp array inside each cmd.
 *	And opens all nessecary pipes by the defined
 *	PIPE endpoints and determines correct file descriptors.
 *	PARMETERS
 *	-
 *	RETURN VALUES
 *	-
 */

void	setup_pipes(t_mini *minishell)
{
	t_cmd	*cmd;

	cmd = minishell->cmd;
	while (cmd)
	{
		if (cmd->endpoint == PIPE)
		{
			if (pipe(cmd->fd_pipe) == -1)
				ft_error(NULL, EXIT, 11);
			cmd->fd_out = cmd->fd_pipe[1];
			cmd->next->fd_in = cmd->fd_pipe[0];
			cmd->is_piped = 1;
			cmd->next->is_piped = 1;
		}
		cmd = cmd->next;
	}
}

static void	get_fileno(int operator, char *filename, t_cmd *cmd)
{
	if (operator == DGREAT || operator == GREAT)
	{
		if (cmd->fd_out != -2)
			close(cmd->fd_out);
	}
	else if (operator == DLESS || operator == LESS)
	{
		if (cmd->fd_in != -2)
			close(cmd->fd_in);
	}
	if (operator == DGREAT)
		cmd->fd_out = open(filename, O_RDWR | O_APPEND | O_CREAT, 0777);
	else if (operator == GREAT)
		cmd->fd_out = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0777);
	else if (operator == LESS)
		cmd->fd_in = open(filename, O_RDONLY);
	// else if (operator == DLESS)
	// 	cmd->fd_in = init_heredoc(filename);
	cmd->errnb = errno;
	if (errno != 0)
		cmd->errfile = filename;
}

static int	check_fds(t_cmd *cmd)
{
	if (cmd->fd_in == -3)
	{
		g_exit_code = 130;
		return (0);
	}
	if (cmd->fd_in == -2)
		cmd->fd_in = STDIN_FILENO;
	if (cmd->fd_out == -2)
		cmd->fd_out = STDOUT_FILENO;
	return (1);
}

/*	DEFINE_REDIRECTS
 *	----------------
 *	DESCRIPTION
 *	This function will define STDIN, STDOUT of each command in line.
 *	PARAMETERS
 *	-
 *	RETURN VALUES
 *	-
 */

int	define_redirects(t_mini *minishell)
{
	t_cmd		*cmd;
	t_token		*redirects;

	cmd = minishell->cmd;
	while (cmd)
	{
		redirects = cmd->redirects;
		while (redirects)
		{
			if (cmd->fd_out == -1 || cmd->fd_in == -1)
				break ;
			get_fileno(redirects->lexema, redirects->next->tkn, cmd);
			redirects = redirects->next;
			redirects = redirects->next;
		}
		if (!check_fds(cmd))
			return (0);
		cmd = cmd->next;
	}
	return (1);
}
