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

static void	clear_tokens(t_token **tokens)
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

void	clear_cmd(t_cmd **cmd)
{
	t_cmd	*curr;
	t_cmd	*tmp;

	curr = *cmd;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		clear_tokens(&tmp->commands);
		clear_tokens(&tmp->redirects);
		if (tmp->envp)
			free_arr((void **)tmp->envp);
		if (tmp->exec)
			free_arr((void **)tmp->exec);
		if (tmp->exec_path)
			free(tmp->exec_path);
		free(tmp);
	}
	*cmd = NULL;
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

void	clear_env(t_mini *minishell)
{
	t_env	*curr;
	t_env	*tmp;

	curr = minishell->env;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	minishell->env = NULL;
}

void	clear(t_mini *minishell)
{
	if (minishell->env)
		clear_env(minishell);
	if (minishell->parser)
		clear_parser(minishell);
	if (minishell->cmd)
		clear_cmd(&minishell->cmd);
	rl_clear_history();
	free(minishell);
}
