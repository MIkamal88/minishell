/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:25:16 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/26 13:25:16 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	OPEN_PIPES
**	----------
**	DESCRIPTION
**	This function opens all necessary pipes by the previously defined
**	PIPE endpoints, and determines the correct file descriptors for 
**	input and output of the executables. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

void	open_pipes(t_mini *minishell)
{
	t_cmd	*cmd;

	cmd = minishell->cmd;
	while (cmd)
	{
		if (cmd->endpoint == PIPE)
		{
			if (pipe(cmd->fd_pipe) == -1)
				ft_error(NULL, 8, 8);
			cmd->fd_out = cmd->fd_pipe[1];
			cmd->is_piped = 1;
			cmd->next->fd_in = cmd->fd_pipe[0];
			cmd->next->is_piped = 1;
		}
		cmd = cmd->next;
	}
}
