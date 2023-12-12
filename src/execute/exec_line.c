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

void	exec_cmds(t_mini *minishell)
{
	t_cmd	*curr;
	t_cmd	*tmp;

	curr = minishell->cmd;
	tmp = curr;
	while (curr)
	{
		exec_pipe_block(minishell);
		curr = curr->next;
	}
	clear_cmd(&tmp);
}

void	exec_line(t_mini *minishell)
{
	setup_pipes(minishell);
	if (!define_redirects(minishell))
		return ;
	exec_cmds(minishell);
}
