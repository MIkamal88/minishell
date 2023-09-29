/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:57:25 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/26 13:57:25 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	DEFINE_REDIRECTS
**	----------------
**	DESCRIPTION
**	This function will define STDIN and STDOUT of each command/process in line.
**	PARAMETERS
**	cmd struct
**	RETURN VALUES
**	-
*/

static t_bool	check_fds(t_cmd *cmd)
{
	if (cmd->fd_in == -3)
	{
		g_glob.exit_code = 130;
		return (FALSE);
	}
	if (cmd->fd_in == -2)
		cmd->fd_in = STDIN_FILENO;
	if (cmd->fd_out == -2)
		cmd->fd_out = STDOUT_FILENO;
	return (TRUE);
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
	/* else if (operator == DLESS) */
	/* 	cmd->fd_in = get_heredoc(filename); */
	cmd->errnb = errno;
	if (errno != 0)
		cmd->errfile = filename;
}

t_bool	define_redirects(t_mini *minishell)
{
	t_cmd	*cmd;
	t_token	*redirects;

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
			return (FALSE);
		cmd = cmd->next;
	}
	return (TRUE);
}
