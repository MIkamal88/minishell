/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:00:18 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/09 09:00:18 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	syntax_word_assignment(t_parser *parser)
{
	t_token	*token;
	int		prev;

	token = parser->tokens;
	prev = -1;
	while (token)
	{
		if (token->lexema == ASSIGN_WORD)
			if (prev == WORD || (prev >= LESS && prev <= DGREAT))
				token->lexema = WORD;
		prev = token->lexema;
		token = token->next;
	}
}

t_bool	syntax_analysis(t_parser *parser)
{
	t_token	*token;
	int		pos;

	token = parser->tokens;
	syntax_word_assignment(parser);
	while (token)
	{
		if (!syntax_pipe(parser->tokens, pos))
			return (FALSE);
		if (!syntax_redirect_io(token))
			return (FALSE);
		if (!syntax_quote(token))
			return (FALSE);
		token = token->next;
		pos++;
	}
	return (TRUE);
}
