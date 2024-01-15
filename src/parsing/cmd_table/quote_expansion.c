/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 07:11:49 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/13 07:11:49 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*	QUOTE_EXPANSION
**	---------------
**	DESCRIPTION
**	Expands the token in which there are quotation marks (either "" or '')
**	as well as any possible variables ($VAR) within "".
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no quotation was found.
*/

static char	*expand_variable(t_env *env, t_token *token, int *pos)
{
	char	*expansion;
	char	*key;
	int		i;

	i = 0;
	if (token->tkn[*pos] == '?')
		expansion = ft_itoa(g_exit_code);
	else if (ft_isdigit(token->tkn[*pos]))
		expansion = NULL;
	else
	{
		while (ft_isalnum(token->tkn[(*pos) + i]))
			i++;
		key = ft_strndup(&token->tkn[*pos], i--);
		expansion = ft_strdup(key_search(env, key));
		free(key);
	}
	*pos = (*pos) + 1 + (i);
	return (expansion);
}

static int	is_variable_expandable(char first_letter)
{
	if (ft_isalnum(first_letter))
		return (1);
	if (first_letter == '?')
		return (1);
	return (0);
}

static void	var_quote_expand(t_env *env, t_token *token, int start, int *size)
{
	char	*prev;
	char	*expansion;
	char	*next;
	int		pos;

	pos = start + (*size);
	if (!is_variable_expandable(token->tkn[pos + 1]))
		return ;
	prev = ft_strndup(token->tkn, pos++);
	expansion = expand_variable(env, token, &pos);
	next = ft_strdup(&token->tkn[pos]);
	if (expansion)
		swap_token(token, ft_strnjoin(3, prev, expansion, next));
	else
		swap_token(token, ft_strnjoin(3, NULL, expansion, next));
	if (*size > 0)
		*size = (*size) + ft_strlen(expansion) - 2;
	if (expansion)
		free(expansion);
	free(prev);
	free(next);
}

void	quote_expansion(t_env *env, t_token **token, int *pos, char quote)
{
	char	*prev;
	char	*next;
	char	*expansion;
	char	*result;
	int		size;

	prev = ft_strndup((*token)->tkn, *pos);
	(*pos)++;
	size = 0;
	while ((*token)->tkn[*pos + size] && (*token)->tkn[*pos + size] != quote)
	{
		if ((*token)->tkn[(*pos) + size] == '$' && quote == '\"')
			var_quote_expand(env, *token, *pos, &size);
		size++;
	}
	expansion = ft_strndup(&(*token)->tkn[*pos], size++);
	result = ft_strjoin(prev, expansion);
	free(prev);
	if (expansion)
		free(expansion);
	next = ft_strdup(&(*token)->tkn[*pos + size]);
	*pos = ft_strlen(result) - 1;
	swap_token(*token, ft_strjoin(result, next));
	free(result);
	free(next);
}
