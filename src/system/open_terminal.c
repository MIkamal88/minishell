/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 08:05:07 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/29 21:01:21 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	read_line(t_mini *minis)
{
	char	*prompt;

	prompt = create_prompt();
	minis->parser = init_parser();
	if (!minis->parser)
		ft_error(NULL, EXIT, 12);
	minis->parser->input = readline(prompt);
	free(prompt);
	if (!minis->parser->input)
	{
		clear(minis);
		ft_error("exit\n", EXIT, 0);
	}
	add_history(minis->parser->input);
}

static t_bool	parse_line(t_mini	*minishell)
{
	tokenize_input(minishell->parser);
	if (!syntax_analysis(minishell->parser))
		return (FALSE);
	cmd_table(minishell);
	return (TRUE);
}

void	open_terminal(t_mini *minishell)
{
	while (TRUE)
	{
		run_signals();
		if (minishell->parser)
			clear_parser(minishell);
		if (minishell->cmd)
			clear_cmd(&minishell->cmd);
		read_line(minishell);
		if (!parse_line(minishell))
			continue ;
		exec_line(minishell);
	}
}
