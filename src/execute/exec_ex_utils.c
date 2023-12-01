/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:02:07 by anayef            #+#    #+#             */
/*   Updated: 2023/11/27 20:27:31 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*append_directory(char *dir, char *executable)
{
	char	*path;
	char	*result;

	path = ft_strjoin(dir, "/");
	if (path == NULL)
	{
		free(executable);
		return (NULL);
	}
	result = ft_strjoin(path, executable);
	free(path);
	free(executable);
	return (result);
}

char	*build_executable_path(char *dir, char *cmd)
{
	return (append_directory(dir, strdup(cmd)));
}

char	**get_directories_from_path(void)
{
	char	*path;

	path = getenv("PATH");
	if (path == NULL)
	{
		printf("PATH variable not found.\n");
		return (NULL);
	}
	return (ft_split(path, ':'));
}
