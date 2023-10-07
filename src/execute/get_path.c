/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 09:12:41 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/30 09:12:41 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*path_finder(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*command;
	int		i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		command = ft_strjoin(path, cmd);
		free(path);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

char	*get_path(t_cmd *cmd)
{
	char	*path;

	if (!*cmd->exec)
		return (NULL);
	if (cmd->exec_path)
		free(cmd->exec_path);
	if (is_builtin(cmd))
		path = ft_strdup(cmd->exec[0]);
	else
		path = path_finder(cmd->exec[0], cmd->envp);
	return (path);
}
