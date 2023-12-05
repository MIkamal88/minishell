/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:43:51 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/29 20:24:15 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*	CMD_TABLE
**	-------------
**	DESCRIPTION
**	The command_table function will assemble the t_token list into two different
**	commands and redirect list, using the operators as endpoints to simple
**	commands (ordered into a t_cmd list).
**	PARAMETERS
**	#1. Minishell struct
**	RETURN VALUES
**	- 
*/

static t_bool	is_redirect(int prev, int curr)
{
	if (curr >= LESS && curr <= DGREAT)
		return (TRUE);
	if (prev >= LESS && prev <= DGREAT)
		return (TRUE);
	return (FALSE);
}

static void	cmd_populate(t_cmd **cmd, t_token **list, int *prev)
{
	t_token	**destiny;

	while (*list && (*list)->lexema < PIPE)
	{
		destiny = &(*cmd)->commands;
		if (is_redirect(*prev, (*list)->lexema))
			destiny = &(*cmd)->redirects;
		token_add_back(destiny, tkn_dup(*list));
		(*prev) = (*list)->lexema;
		(*list) = (*list)->next;
	}
	if (*list)
	{
		(*cmd)->endpoint = (*list)->lexema;
		(*prev) = (*list)->lexema;
		(*list) = (*list)->next;
	}
}

void	cmd_table(t_mini *minishell)
{
	t_cmd	*cmd_node;
	t_token	*list;
	int		id;
	int		prev;

	list = minishell->parser->tokens;
	prev = -1;
	id = 0;
	while (list)
	{
		cmd_node = cmd_create(minishell->envp, id);
		cmd_populate(&cmd_node, &list, &prev);
		cmd_add_back(&minishell->cmd, cmd_node);
		id++;
	}
	cmd_expansion(minishell);
	cmd_list(minishell);
}
