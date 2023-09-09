/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:51:52 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/09 10:51:52 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_bool	syntax_pipe(t_token *token, int pos)
{
	if (token->lexema == PIPE)
	{
		if (pos == 0 || !token->next)
		{
			ft_error("minishell: syntax error near unexpected token\n", \
						SYNT_ERR, 2);
			return (FALSE);
		}
	}
	return (TRUE);
}

t_bool	syntax_redirect_io(t_token *token)
{
	if (token->lexema == LESS || token->lexema == DLESS || \
		token->lexema == GREAT || token->lexema == DGREAT)
	{
		if (!token->next)
		{
			ft_error(NULL, SYNT_ERR, 2);
			return (FALSE);
		}
		else if (token->next->lexema != WORD && \
			token->next->lexema != ASSIGN_WORD)
		{
			ft_error("minishell: syntax error near unexpected token\n", \
						SYNT_ERR, 2);
			return (FALSE);
		}
	}
	return (TRUE);
}

t_bool	syntax_quote(t_token *token)
{
	int	flag;
	int	i;

	flag = -1;
	i = 0;
	if (!token->next)
	{
		while (token->tkn[i])
		{
			if (flag == -1 && (token->tkn[i] == '\"' || token->tkn[i] == '\''))
				flag = i;
			else if (flag != -1 && token->tkn[i] == token->tkn[flag])
				flag = -1;
			i++;
		}
		if (flag != -1)
		{
			ft_error("minishell: syntax error: quote missing\n", SYNT_ERR_2, 2);
			return (FALSE);
		}
	}
	return (TRUE);
}
