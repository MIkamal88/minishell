/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:50:04 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/29 21:08:30 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clear_tokens(t_token **tokens)
{
	t_token	*curr;
	t_token	*tmp;

	curr = *tokens;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp->tkn);
		free(tmp);
	}
	*tokens = NULL ;
}

void	clear_cmd(t_mini *minishell)
{
	t_cmd	*curr;
	t_cmd	*tmp;

	curr = minishell->cmd;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		clear_tokens(&tmp->commands);
		clear_tokens(&tmp->redirects);
		if (tmp->exec)
			free_arr((void **)tmp->exec);
		if (tmp->exec_path)
			free(tmp->exec_path);
		free(tmp);
	}
	minishell->cmd = NULL;
}

void	clear_parser(t_mini *minishell)
{
	if (!minishell->parser)
		return ;
	if (minishell->parser->input)
		free(minishell->parser->input);
	if (minishell->parser->tokens)
		clear_tokens(&minishell->parser->tokens);
	free(minishell->parser);
	minishell->parser = NULL;
}

void	clear(t_mini *minishell)
{
	if (minishell->envp)
		free_arr((void **)minishell->envp);
	if (minishell->parser)
		clear_parser(minishell);
	if (minishell->cmd)
		clear_cmd(minishell);
	rl_clear_history();
	free(minishell);
}
