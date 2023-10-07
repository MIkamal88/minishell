/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_sigs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 07:20:42 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/30 07:20:42 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	EXEC_COMMANDS_SIGNALS
**	---------------------
**	DESCRIPTION
**	It changes the default signals received by specific shortcuts when executing
**	the exec_commands function, to avoid that these signals will respond to the
**	parent shell, instead of the current. 
**	PARAMETERS
**	-
**	RETURN VALUES
**	-
*/

static void	quit_process(int signal)
{
	(void)signal;
	ft_error(NULL, 3, 310);
}

static void	interrupt_process(int signal)
{
	(void)signal;
	ft_error(NULL, 3, 300);
}

void	exec_commands_child_signals(void)
{
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_process);
}

static void	parent_sig(int signal)
{
	if (signal == SIGQUIT)
		ft_error(NULL, 3, 310);
	if (signal == SIGINT)
		ft_error(NULL, 3, 300);
}

void	exec_commands_parent_signals(void)
{
	signal(SIGQUIT, parent_sig);
	signal(SIGINT, parent_sig);
}
