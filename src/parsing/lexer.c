/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:17:59 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/06 20:17:59 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_key_alnum(char *s, int stop)
{
	int	i;

	i = 0;
	while (i < stop)
	{
		if (!ft_isalnum(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_word(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '=' && i != 0)
		{
			if (ft_isdigit(token[0]) || token[0] == '=')
				return (WORD);
			if (is_key_alnum(token, i))
				return (ASSIGN_WORD);
		}
		i++;
	}
	return (WORD);
}

static int	check_token(char *token)
{
	if (ft_strlen(token) == 1)
	{
		if (token[0] == '|')
			return (PIPE);
		if (token[0] == '>')
			return (GREAT);
		if (token[0] == '<')
			return (LESS);
	}
	if (ft_strlen(token) == 2)
	{
		if (token[0] == '>' && token[1] == '>')
			return (DGREAT);
		if (token[0] == '<' && token[1] == '<')
			return (DLESS);
	}
	return (check_word(token));
}

int	lexical_analysis(char *token)
{
	int	lexema;

	lexema = check_token(token);
	return (lexema);
}
