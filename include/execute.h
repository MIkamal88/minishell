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

int		is_builtin(t_cmd *cmd);
int		is_forked(t_cmd *cmd);

int		ft_exit(char **exec);
char	*get_pwd(void);
int		ft_pwd(void);
int		ft_cd(char **exec);//??//
int		ft_echo(char **exec);

void	exec_builtin_in_child(t_cmd *cmd);
void	exec_builtin_in_parent(t_cmd *cmd);

void	change_exec(t_cmd *cmd, int pos);
void	assign_word(t_cmd *cmd);

void	close_fds(t_cmd *cmd);
void	close_fd(t_cmd *cmd, int flag);

char	*get_path(t_cmd *cmd);
void	exec_commands_child_signals(void);
void	exec_commands_parent_signals(void);

#endif
