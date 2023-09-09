/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 08:05:07 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/01 08:05:07 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	read_line(t_mini *minishell)
{
	char	*prompt;

	prompt = create_prompt();
	minishell->parser = init_parser();
	minishell->parser->input = readline(prompt);
	if (minishell->parser->input)
		add_history(minishell->parser->input);
	free(prompt);
}

static t_bool	parse_line(t_mini	*minishell)
{
	tokenize_input(minishell->parser);
	if (!syntax_analysis(minishell->parser))
		return (FALSE);
	if (ft_strcmp(minishell->parser->input, "exit") == 0)
	{
		clear(minishell);
		exit(0);
	}
	return (TRUE);
}

void	open_terminal(t_mini *minishell)
{
	while (TRUE)
	{
		// Signals;
		clear_parser(minishell->parser);
		read_line(minishell);
		if (!parse_line(minishell))
			continue ;
		// exec_line;
	}
}
