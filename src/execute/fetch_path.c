/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:37:02 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/09 13:37:02 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**create_path_list(t_env *env)
{
	char	**path;
	char	*temp;

	path = NULL;
	temp = key_search(env, "PATH");
	if (temp)
		path = ft_split(temp, ':');
	return (path);
}

static void	free_path_list(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

static void	check_paths(t_cmd *cmd, char **path_list, char **path)
{
	char	*curr_path;
	int		i;

	i = -1;
	while (path_list[++i])
	{
		curr_path = ft_strnjoin(3, path_list[i], "/", cmd->exec[0]);
		if (access(curr_path, F_OK) == 0)
		{
			*path = curr_path;
			break ;
		}
		free(curr_path);
	}
	free_path_list(path_list);
}

static char	*setup_path(t_cmd *cmd, t_env *env)
{
	char	*path;
	char	**path_list;

	path = NULL;
	if (ft_strchr(cmd->exec[0], '/') != NULL)
	{
		path = ft_strdup(cmd->exec[0]);
		return (path);
	}
	path_list = create_path_list(env);
	if (path_list)
		check_paths(cmd, path_list, &path);
	if (!path && !access(cmd->exec[0], F_OK | X_OK))
		path = ft_strdup(cmd->exec[0]);
	return (path);
}

char	*fetch_path(t_cmd *cmd, t_env *env)
{
	char	*path;

	if (!*cmd->exec)
		return (NULL);
	if (cmd->exec_path)
		free(cmd->exec_path);
	if (is_builtin(cmd->exec[0]))
		path = ft_strdup(cmd->exec[0]);
	else
	{
		path = setup_path(cmd, env);
		if (!path)
		{
			if (!key_search(env, "PATH"))
				ft_error(cmd->exec[0], F_D_MIA, 127);
			else
				ft_error(cmd->exec[0], CMD_MIA, 127);
		}
	}
	return (path);
}
