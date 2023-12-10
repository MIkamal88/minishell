/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sigs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:14:47 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/09 17:14:47 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	parent_sig(int signal)
{
	if (signal == SIGQUIT)
		ft_error(NULL, QUIT, 131);
	if (signal == SIGINT)
		ft_error(NULL, NEW_L, 130);
}

void	exec_cmd_parent_sig(void)
{
	signal(SIGINT, parent_sig);
	signal(SIGQUIT, parent_sig);
}

static void	interrupt_process(int signal)
{
	(void)signal;
	ft_error(NULL, EXIT, 130);
}

static void	quit_process(int signal)
{
	(void)signal;
	ft_error(NULL, EXIT, 131);
}

void	exec_cmd_child_sig(void)
{
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_process);
}
