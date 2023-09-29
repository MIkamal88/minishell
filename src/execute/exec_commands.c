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
