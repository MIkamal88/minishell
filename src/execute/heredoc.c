/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:36:08 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/06 12:36:08 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	write_to_pipe(char *limiter, int *fd, t_mini *minishell)
{
	char	*line;
	int		len;

	get_heredoc_child_signal();
	line = readline("> ");
	len = ft_strlen(limiter);
	while (TRUE)
	{
		if (!line)
			ft_error(limiter, HERE_DOC_EOF, 22);
		if (!line || (!ft_strncmp(limiter, line, len) && line[len] == '\0'))
			break ;
		write(*fd, line, ft_strlen(line));
		write(*fd, "\n", 1);
		free(line);
		line = readline("> ");
	}
	free(line);
	close(*fd);
	free(limiter);
	clear(minishell);
	ft_error("", EXIT, 0);
}

static int	interrupt_heredoc(int *fd)
{
	close(fd[0]);
	return (-3);
}

static int	exit_heredoc(t_mini *minishell)
{
	clear(minishell);
	ft_error("", EXIT, 35);
	return (-3);
}

int	init_heredoc(char *filename, t_mini *minishell)
{
	int		fd[2];
	int		pid;
	int		wstatus;

	if (pipe(fd) == -1)
		return (exit_heredoc(minishell));
	pid = fork();
	if (pid == -1)
		return (exit_heredoc(minishell));
	if (!pid)
	{
		close(fd[0]);
		write_to_pipe(ft_strdup(filename), &fd[1], minishell);
	}
	get_heredoc_parent_signal();
	close(fd[1]);
	waitpid(pid, &wstatus, 0);
	if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) == 130)
		return (interrupt_heredoc(fd));
	return (fd[0]);
}
