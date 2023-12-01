/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:49:29 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/22 21:38:35 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*	COMMAND_LIST
**	------------
**	DESCRIPTION
**	The command_list function transforms the linked list of command tokens into
**	an double pointer array of strings, ready for execve. 
**	PARAMETERS
**	#1. Minishell struct
**	RETURN VALUES
**	- 
*/

static char	**put_in_list(t_token *token)
{
	int		size;
	int		i;
	char	**list;

	size = tkn_len(token)+ 1;
	list = ft_calloc(sizeof(char *), size);
	if (!list)
		ft_error(NULL, EXIT, 12);
	i = 0;
	while (token)
	{
		list[i] = ft_strdup(token->tkn);
		token = token->next;
		i++;
	}
	return (list);
}

void	cmd_list(t_mini *minishell)
{
	t_cmd	*cmd;

	cmd = minishell->cmd;
	while (cmd)
	{
		cmd->exec = put_in_list(cmd->commands);
		cmd = cmd->next;
	}
}
