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

void	exec_builtin(char **args, t_mini *minishell)
{
	if (ft_strcmp(args[0], "echo") == 0)
		ft_echo(args);
	else if (ft_strcmp(args[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(args[0], "cd") == 0)
		ft_cd(args);
	else if (ft_strcmp(args[0], "exit") == 0)
		ft_exit(args, minishell);
	else if (ft_strcmp(args[0], "export") == 0)
		ft_export(minishell, args);
	else if (ft_strcmp(args[0], "unset") == 0)
		ft_unset(minishell, args);
	else if (ft_strcmp(args[0], "env") == 0)
		ft_env(minishell, args);
}
