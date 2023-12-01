/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:11:54 by anayef            #+#    #+#             */
/*   Updated: 2023/11/27 20:23:21 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*search_executable_in_directories(char **directories, char *cmd)
{
	int		i;
	char	*executable;

	i = 0;
	while (directories[i] != NULL)
	{
		executable = build_executable_path(directories[i], cmd);
		if (executable != NULL)
		{
			if (access(executable, X_OK) == 0)
				return (executable);
			free(executable);
		}
		i++;
	}
	return (NULL);
}

int	execute_command(char **args, char **envp, char **directories)
{
	char	*executable;

	executable = search_executable_in_directories(directories, args[0]);
	if (executable != NULL)
	{
		execve(executable, args, envp);
		printf("Exec failed\n");
		free(executable);
		return (1);
	}
	else
	{
		printf("Command not found in PATH\n");
		return (0);
	}
}

void	child_process(char **args, char **envp)
{
	char	**directories;
	int		result;

	directories = get_directories_from_path();
	if (directories == NULL)
		exit(1);
	result = execute_command(args, envp, directories);
	if (result == 0)
		exit(1);
	else
		exit(0);
}

void	exec_external_cmd(char **args, char **envp)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid < 0)
	{
		printf("Fork failed\n");
		return ;
	}
	if (pid == 0)
		child_process(args, envp);
	else
		waitpid(pid, &status, 0);
}
