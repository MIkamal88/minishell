/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:45:55 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/12 19:45:55 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	setup_cmd(t_mini *minishell, t_cmd **ptr)
{
	exec_cmd_parent_sig();
	(*ptr)->exec_path = fetch_path(*ptr, minishell->env);
	(*ptr)->envp = create_envp(minishell->env);
}

void	wait_all(int pid[MAX_PID], int id)
{
	int		max_id;
	int		wstatus;

	if (id == -1)
		return ;
	max_id = id;
	id = -1;
	wstatus = 0;
	while (++id <= max_id)
		waitpid(pid[id], &wstatus, 0);
	if (WIFEXITED(wstatus))
		g_exit_code = WEXITSTATUS(wstatus);
}

void	dup2_close_fds(t_cmd *cmd)
{
	if (cmd->fd_in > 2)
		dup2(cmd->fd_in, STDIN_FILENO);
	if (cmd->fd_out > 2)
		dup2(cmd->fd_out, STDOUT_FILENO);
	close_fds(cmd);
}
