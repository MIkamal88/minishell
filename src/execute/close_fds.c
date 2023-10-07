/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 06:46:13 by m_kamal           #+#    #+#             */
/*   Updated: 2023/10/02 06:46:13 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <unistd.h>

void	close_fds(t_cmd *comm)
{
	t_cmd	*cmd;

	cmd = comm;
	while (cmd)
	{
		close_fd(cmd, BOTH);
		cmd = cmd->next;
	}
}

void	close_fd(t_cmd *cmd, int fd_flag)
{
	if ((fd_flag == IN || fd_flag == BOTH) && cmd->fd_in > 2)
		close(cmd->fd_in);
	if ((fd_flag == OUT || fd_flag == BOTH) && cmd->fd_out > 2)
		close(cmd->fd_out);
}
