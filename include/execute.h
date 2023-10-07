/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 07:33:54 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/30 07:33:54 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "parser.h"
# define MAX_PID	1024

enum e_fd{
	IN,
	OUT,
	BOTH,
};

void	exec_commands_child_signals(void);
void	exec_commands_parent_signals(void);
void	exec_child(t_cmd *cmd);
void	exec_builtin_in_parent(t_cmd *cmd);
void	exec_builtin_in_child(t_cmd *cmd);
void	close_fds(t_cmd *comm);
void	close_fd(t_cmd *cmd, int fd_flag);
char	*get_path(t_cmd *cmd);

t_bool	is_builtin(t_cmd *cmd);
t_bool	is_forked(t_cmd *cmd);

#endif
