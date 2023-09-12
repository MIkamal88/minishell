/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:02:48 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/07 08:02:48 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*create_token(char *tkn, int flag)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->tkn = tkn;
	if (!flag)
		token->lexema = lexical_analysis(tkn);
	else
		token->lexema = WORD;
	token->next = NULL;
	return (token);
}

static void	add_part(t_parser *parser, const char *input, size_t size)
{
	t_token	*token;
	char	*tkn;

	while (*input == ' ')
	{
		size--;
		input++;
	}
	if (!size || !(*input))
		return ;
	tkn = ft_strndup(input, size);
	token = create_token(tkn, 0);
	token_add_back(&parser->tokens, token);
}

void	tokenize_input(t_parser *parser)
{
	int		i;
	int		prev;
	int		next;
	int		size;

	i = 0;
	prev = i;
	next = i;
	size = 0;
	while (TRUE)
	{
		if (is_new_token(parser->input, i, prev))
			next = i;
		size = next - prev;
		if (size > 0)
			add_part(parser, &parser->input[prev], size);
		if (!parser->input[i])
			break ;
		prev = next;
		i++;
	}
}
