/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 08:03:16 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/10 08:03:16 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_cmd	*cmd_create(char **envp, int id)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		ft_error(NULL, EXIT, 12);
	cmd->id = id;
	cmd->commands = NULL;
	cmd->redirects = NULL;
	cmd->endpoint = -1;
	cmd->is_piped = FALSE;
	cmd->exec = NULL;
	cmd->exec_path = NULL;
	cmd->envp = envp;
	cmd->fd_in = -2;
	cmd->fd_out = -2;
	cmd->errnb = 0;
	cmd->errfile = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	cmd_add_back(t_cmd **cmd, t_cmd *last)
{
	t_cmd	*cmd_list;

	cmd_list = (*cmd);
	if (!cmd_list)
		(*cmd) = last;
	else
	{
		while (cmd_list->next)
			cmd_list = cmd_list->next;
		cmd_list->next = last;
	}
}

void	swap_token(t_token *token, char	*new_token)
{
	free(token->tkn);
	token->tkn = new_token;
}
