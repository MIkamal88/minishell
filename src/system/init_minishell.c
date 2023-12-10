/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 08:05:07 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/29 21:11:03 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_mini	*init_minishell(char **envp)
{
	t_mini	*minishell;

	minishell = malloc(sizeof(t_mini));
	if (!minishell)
		ft_error(NULL, EXIT, 12);
	minishell->parser = init_parser();
	if (!minishell->parser)
		ft_error(NULL, EXIT, 12);
	minishell->cmd = NULL;
	minishell->env = NULL;
	while (*envp)
	{
		add_env(minishell, get_env_name(*envp), get_env_value(*envp));
		envp++;
	}
	return (minishell);
}

t_parser	*init_parser(void)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	if (!parser)
		ft_error(NULL, EXIT, 12);
	parser->input = NULL;
	parser->tokens = NULL;
	return (parser);
}
