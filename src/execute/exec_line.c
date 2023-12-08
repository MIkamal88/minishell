/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:38:02 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/29 21:13:17 by anayef           ###   ########.fr       */
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

void	exec_line(t_mini *minishell)
{
	open_pipes(minishell);
	if (!define_redirects(minishell))
		return ;
	exec_cmds(minishell);
}

void	exec_cmds(t_mini *minishell)
{
	t_cmd	*cmd;
	char	**args;

	cmd = minishell->cmd;
	cmd->envp = create_envp(minishell->env);
	while (cmd)
	{
		args = cmd->exec;
		if (args != NULL)
		{
			if (is_builtin(args[0]))
				exec_builtin(args, minishell);
			else
				exec_external_cmd(args, cmd->envp);
		}
		cmd = cmd->next;
	}
}
