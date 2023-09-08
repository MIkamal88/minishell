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
	token = create_token(tkn);
	token_add_back(&parser->tokens, token);
}

void	tokenize_input(t_parser *parser)
{
	char	*input;
	size_t	i;
	size_t	prev;
	size_t	next;
	size_t	size;

	input = parser->input;
	i = 0;
	prev = i;
	next = i;
	size = 0;
	while (TRUE)
	{
		if (is_new_token(input, i, prev))
			next = i;
		size = next - prev;
		if (size > 0)
			add_part(parser, &input[prev], size);
		if (!input[i])
			break ;
		prev = next;
		i++;
	}
}
