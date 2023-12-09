/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_with_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:49:06 by anayef            #+#    #+#             */
/*   Updated: 2023/12/08 21:51:17 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_io_descriptors(t_cmd *cmd)
{
	if (cmd->fd_in != 0)
	{
		dup2(cmd->fd_in, 0);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != 1)
	{
		dup2(cmd->fd_out, 1);
		close(cmd->fd_out);
	}
	close(cmd->fd_pipe[0]);
	if (cmd->next != NULL)
	{
		dup2(cmd->fd_pipe[1], 1);
		close(cmd->fd_pipe[1]);
	}
}

void	execute(t_cmd *cmd, t_mini *minishell)
{
	char	**args;

	args = cmd->exec;
	if (args != NULL)
	{
		if (is_builtin(args[0]))
			exec_builtin(args, minishell);
		else
			exec_external_cmd(args, cmd->envp);
	}
	exit(EXIT_SUCCESS);
}

void	create_pipe(int pipefd[])
{
	if (pipe(pipefd) == -1)
	{
		perror("Pipe creation failed");
		exit(EXIT_FAILURE);
	}
}

void	execute_p(t_cmd *cmd, t_mini *minishell, int pipefd[])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		set_io_descriptors(cmd);
		execute(cmd, minishell);
	}
	else if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		close(pipefd[1]);
		close_fd(cmd->fd_in);
		if (cmd->next != NULL)
			execute_with_pipe(cmd->next, pipefd[0], 1, minishell);
		waitpid(pid, NULL, 0);
		close(pipefd[0]);
	}
}

void	execute_with_pipe(t_cmd *cmd, int input_fd,
	int output_fd, t_mini *minishell)
{
	int	pipefd[2];

	cmd->fd_in = input_fd;
	cmd->fd_out = output_fd;
	create_pipe(pipefd);
	execute_p(cmd, minishell, pipefd);
}
