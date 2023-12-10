/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:53:38 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/09 16:53:38 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_fds(t_cmd *cmd)
{
	t_cmd	*ptr;

	ptr = cmd;
	while (ptr)
	{
		close_fd(ptr, BOTH);
		ptr = ptr->next;
	}
}

void	close_fd(t_cmd *cmd, int flag)
{
	if ((flag == IN || flag == BOTH) && cmd->fd_in > 2)
		close(cmd->fd_in);
	if ((flag == OUT || flag == BOTH) && cmd->fd_out > 2)
		close(cmd->fd_out);
}
