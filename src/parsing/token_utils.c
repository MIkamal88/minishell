/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:14:40 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/07 08:14:40 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*tkn_dup(t_token *original)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		ft_error(NULL, EXIT, 12);
	token->tkn = ft_strdup(original->tkn);
	token->lexema = original->lexema;
	token->next = NULL;
	return (token);
}

void	token_add_back(t_token **list, t_token *token)
{
	t_token	*tmp;

	tmp = *list;
	if (!tmp)
		(*list) = token;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = token;
	}
}

static t_bool	is_in_quotes(const char *input, int index)
{
	int		is_in;
	int		i;

	is_in = -1;
	i = 0;
	while (i < index)
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			if (is_in == -1)
				is_in = i;
			else if (is_in != -1 && input[is_in] == input[i])
				is_in = -1;
		}
		i++;
	}
	if (is_in != -1)
		return (TRUE);
	return (FALSE);
}

static t_bool	is_part_of_last(char curr, char last)
{
	if (curr == '|' && last == '|')
		return (FALSE);
	if (curr == '>' && last == '>')
		return (FALSE);
	if (curr == '<' && last == '<')
		return (FALSE);
	if (curr == '&' && last == '&')
		return (FALSE);
	if (curr == ' ' && last == ' ')
		return (FALSE);
	return (TRUE);
}

t_bool	is_new_token(const char *input, int index, int prev)
{
	if (!index || !input[index])
		return (TRUE);
	if (is_in_quotes(input, index))
		return (FALSE);
	if (ft_strchr(METACHARS, input[index]))
	{
		if (index - prev == 1)
			return (is_part_of_last(input[index], input[index - 1]));
		if (input[index] == ' ' && input[index - 1] == ' ')
			return (FALSE);
		return (TRUE);
	}
	if (index > 0 && ft_strchr(METACHARS, input[index - 1]))
		return (TRUE);
	return (FALSE);
}
