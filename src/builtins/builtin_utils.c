/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:34:23 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/12 15:34:23 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	change_exec(t_cmd *cmd, int pos)
{
	t_token	*tkn;
	size_t	size;
	char	**list;
	int		i;

	tkn = cmd->commands;
	i = -1;
	while (++i < pos)
		tkn = tkn->next;
	size = tkn_len(tkn) + 1;
	list = ft_calloc(sizeof(char *), size);
	if (!list)
		ft_error(NULL, 0, 11);
	i = -1;
	while (tkn)
	{
		list[++i] = ft_strdup(tkn->tkn);
		tkn = tkn->next;
	}
	free_arr((void **)cmd->exec);
	cmd->exec = list;
}

void	assign_word(t_mini *minishell)
{
	t_cmd	*ptr;
	t_token	*tmp;
	int		pos;
	int		i;

	ptr = minishell->cmd;
	tmp = ptr->commands;
	i = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->lexema == WORD)
		{
			pos = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	if (!pos)
		exec_export(minishell, (*ptr->exec));
	else
	{
		change_exec(ptr, pos);
		exec_cmd(minishell);
	}
}
