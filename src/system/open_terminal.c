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

static void	read_line(t_mini *minis)
{
	char	*prompt;

	prompt = create_prompt();
	minis->parser = init_parser();
	minis->parser->input = readline(prompt);
	free(prompt);
	if (!minis->parser->input || (ft_strcmp(minis->parser->input, "exit") == 0))
	{
		clear(minis);
		ft_error("exit\n", 2, 0);
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
			clear_cmd(minishell);
		read_line(minishell);
		if (!parse_line(minishell))
			continue ;
		// exec_line(minishell);
	}
}
