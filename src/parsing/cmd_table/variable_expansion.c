/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:03:30 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/25 22:03:30 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*	VARIABLE_EXPANSION
**	------------------
**	DESCRIPTION
**	It expands the variable key preceded by $ into its value, and breaks the
**	token into multiple ones, splitted by any space char that can exist in the
**	expanded variable value.
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no variable was found.
*/

static int	is_variable_expandable(char first_letter)
{
	if (ft_isalnum(first_letter))
		return (1);
	if (first_letter == '?')
		return (1);
	return (0);
}

static char	**split_variable_expansion(char	*expansion)
{
	char	**result;

	if (!expansion)
	{
		result = malloc(1 * sizeof(char *));
		result[0] = NULL;
	}
	else
		result = ft_split(expansion, ' ');
	if (expansion)
		free(expansion);
	return (result);
}

static char	**expand_variable(t_env *env, t_token *tkn, int *pos)
{
	char	*expansion;
	char	*key;
	int		i;

	i = 0;
	if (tkn->tkn[*pos] == '?')
		expansion = ft_itoa(g_exit_code);
	else if (ft_isdigit(tkn->tkn[*pos]))
		expansion = NULL;
	else
	{
		while (ft_isalnum(tkn->tkn[(*pos) + i]))
			i++;
		key = ft_strndup(&tkn->tkn[*pos], i--);
		expansion = ft_strdup(key_search(env, key));
		free(key);
	}
	(*pos) = (*pos) + 1 + (i);
	return (split_variable_expansion(expansion));
}

static void	clean_expansion(char **split, char *next)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	if (next)
		free(next);
}

void	variable_expansion(t_env *env, t_token **tkn, int *pos)
{
	char	*prev;
	char	*next;
	char	**expansion_split;
	t_token	*last;
	int		i;

	if (!is_variable_expandable((*tkn)->tkn[(*pos) + 1]))
		return ;
	prev = ft_strndup((*tkn)->tkn, (*pos)++);
	expansion_split = expand_variable(env, *tkn, pos);
	next = ft_strdup(&(*tkn)->tkn[*pos]);
	last = (*tkn)->next;
	(*tkn)->next = NULL;
	i = 0;
	swap_token(*tkn, ft_strjoin(prev, expansion_split[i]));
	while (expansion_split[0] && expansion_split[++i])
		token_add_back(tkn, create_token(ft_strdup(expansion_split[i]), 1));
	while ((*tkn)->next)
		(*tkn) = (*tkn)->next;
	free(prev);
	prev = (*tkn)->tkn;
	swap_token(*tkn, ft_strjoin(prev, next));
	(*pos) = ft_strlen(expansion_split[i]) - 1;
	(*tkn)->next = last;
	clean_expansion(expansion_split, next);
}
