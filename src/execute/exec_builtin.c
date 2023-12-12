/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:23:43 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/27 21:14:44 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_builtin_parent(t_mini *minishell)
{
	t_cmd	*ptr;

	ptr = minishell->cmd;
	if (!ft_strncmp(ptr->exec_path, "cd\0", 3))
		g_exit_code = ft_cd(minishell, ptr->exec);
	else if (!ft_strncmp(ptr->exec_path, "export\0", 7))
		g_exit_code = ft_export(minishell, ptr->exec);
	else if (!ft_strncmp(ptr->exec_path, "unset\0", 6))
		g_exit_code = ft_unset(minishell, ptr->exec);
	else if (!ft_strncmp(ptr->exec_path, "exit\0", 5))
		g_exit_code = ft_exit(ptr->exec, minishell);
	else if (is_assign_word(ptr->exec_path))
		assign_word(minishell);
	envp_swap(minishell, ptr);
}

void	exec_builtin_child(t_mini *minishell)
{
	t_cmd	*ptr;

	ptr = minishell->cmd;
	if (!ft_strncmp(ptr->exec_path, "env\0", 4))
		g_exit_code = ft_env(minishell, ptr->exec);
	else if (!ft_strncmp(ptr->exec_path, "export\0", 7))
		g_exit_code = ft_export(minishell, ptr->exec);
	else if (!ft_strncmp(ptr->exec_path, "echo\0", 5))
		g_exit_code = ft_echo(ptr->exec);
	else if (!ft_strncmp(ptr->exec_path, "pwd\0", 4))
		g_exit_code = ft_pwd();
}

t_bool	is_forked(t_mini *minishell)
{
	t_cmd	*ptr;

	ptr = minishell->cmd;
	if (!ft_strncmp(ptr->exec_path, "cd\0", 3)
		|| !ft_strncmp(ptr->exec_path, "unset\0", 6)
		|| !ft_strncmp(ptr->exec_path, "exit\0", 5))
	{
		if (!ptr->is_piped)
			exec_builtin_parent(minishell);
		return (FALSE);
	}
	else if (!ft_strncmp(ptr->exec_path, "export\0", 7)
		&& ptr->exec[1] && *ptr->exec[1])
	{
		if (!ptr->is_piped)
			exec_builtin_parent(minishell);
		return (FALSE);
	}
	return (TRUE);
}
