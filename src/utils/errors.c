/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:14:00 by m_kamal           #+#    #+#             */
/*   Updated: 2023/08/31 14:14:01 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <asm-generic/errno-base.h>
#include <unistd.h>

void	terminate(t_mini *minishell)
{
	clear(minishell);
	exit(g_glob.exit_code);
}

void	exit_err(char *errfile, int errnb)
{
	if (errnb == EACCES)
		ft_error(errfile, CMD_P, 12);
	if (errnb == ENOENT)
		ft_error(errfile, NOT_DIR, 14);
	else
		ft_error(errfile, CMD_NA, 13);
}

void	syntax_error(char *s, int err)
{
	if (err == SYNT_ERR)
		write(2, &s, ft_strlen(s));
}

void	cmd_error(char *s, int err)
{
	char	*str;

	if (err == CMD_P)
	{
		str = " Permission Denied\n";
		write(2, &s, ft_strlen(s));
		write(2, &str, ft_strlen(str));
	}
	if (err == CMD_NA)
	{
		str = " Command not found\n";
		write(2, &s, ft_strlen(s));
		write(2, &str, ft_strlen(s));
	}
	if (err == NOT_DIR)
	{
		str = " No Such file or directory\n";
		write(2, &s, ft_strlen(s));
		write(2, &str, ft_strlen(str));
	}
}

void	ft_error(char *s, int err, int code)
{
	g_glob.exit_code = code;
	if (err == SYNT_ERR || err == SYNT_ERR_2)
		syntax_error(s, err);
	if (err == CMD_P || err == CMD_NA || err == NOT_DIR)
		cmd_error(s, err);
}
