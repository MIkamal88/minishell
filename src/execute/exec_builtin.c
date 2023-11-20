/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:23:43 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/08 15:23:43 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_builtin_in_parent(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "cd\0", 3))
		g_exit_code = ft_cd(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "export\0", 7))
		g_exit_code = ft_export(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "unset\0", 6))
		g_exit_code = ft_unset(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "exit\0", 5))
		g_exit_code = ft_exit(cmd->exec);
	else if (is_assign_word(cmd->exec_path))
		assign_word(cmd);
	envp_swap(cmd);
}

void	exec_builtin_in_child(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->exec_path, "env\0", 4))
		g_exit_code = ft_env(cmd);
	else if (!ft_strncmp(cmd->exec_path, "export\0", 7))
		g_exit_code = ft_export(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "echo\0", 5))
		g_exit_code = ft_echo(cmd->exec);
	else if (!ft_strncmp(cmd->exec_path, "pwd\0", 4))
		g_exit_code = ft_pwd();
}
