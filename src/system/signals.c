/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:46:13 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/07 17:46:13 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	CHANGE_INPUT_SIGNALS
**	--------------------
**	DESCRIPTION
**	It changes the default signals received by specific shortcuts when executing
**	the main minishell function, to avoid that these signals will respond to the
**	parent shell, instead of the current. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

static void	reprompt(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	run_signals(void)
{
	signal(SIGINT, reprompt);
	signal(SIGQUIT, SIG_IGN);
}
