/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:00:18 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/22 21:34:31 by anayef           ###   ########.fr       */
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
	pos = 0;
	syntax_word_assignment(parser);
	while (token)
	{
		if (!syntax_pipe(token, pos))
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

int	is_assign_word(char *token)
{
	int	i;

	if (ft_strchr(token, '='))
	{
		i = 0;
		while (token[i] != '=')
		{
			if (!ft_isalnum(token[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
