/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:50:04 by m_kamal           #+#    #+#             */
/*   Updated: 2023/08/31 16:50:05 by m_kamal          ###   ########.fr       */
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

void	clear_parser(t_parser *parser)
{
	if (!parser)
		return ;
	if (parser->input)
		free(parser->input);
	if (parser->tokens)
		clear_tokens(&parser->tokens);
	free(parser);
	parser = NULL;
}

void	clear(t_mini *minishell)
{
	if (minishell->envp)
		free_arr(minishell->envp);
	if (minishell->parser)
		clear_parser(minishell->parser);
	free(minishell);
	rl_clear_history();
}
