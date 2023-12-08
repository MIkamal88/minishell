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

static void	cd_err(char *str, int err)
{
	if (err == 11)
	{
		write_err("Minishell: cd: ");
		write_err(str);
		write_err(" not set\n");
	}
	if (err == 12)
	{
		write_err("Minishell: cd: ");
		write_err(str);
		write_err(": No such file or directory\n");
	}
}

static void	syntax_err(char *str, int err)
{
	if (err == 21)
	{
		write_err("Minishell: Syntax error near unexpected token ");
		write_err(str);
		write_err("\n");
	}
	if (err == 22)
		write_err("Minishell: Quote missing\n");
}

static void	redirect_err(char *str, int err)
{
	if (err == 31)
	{
		write_err("Minishell: ");
		write_err(str);
		write_err(": Permission denied");
	}
	if (err == 32)
	{
		write_err("Minishell: ");
		write_err(str);
		write_err(": No such file or directory\n");
	}
	if (err == 33)
	{
		write_err("Minishell: warning: here-document delimited by \
			end-of-file (wanted `");
		write_err(str);
		write_err("')\n");
	}
	if (err == 34)
		write_err("Quit\n");
	if (err == 35)
		write_err("\n");
}

static void	exec_err(char *str, int err)
{
	if (err == 14)
	{
		write_err("Minishell: ");
		write_err(str);
		write_err(": Too many arguments\n");
	}
	if (err == 15)
	{
		write_err(str);
		write_err(": Command not found\n");
	}
	if (err == 16)
	{
		write_err("Minishell: export: '");
		write_err(str);
		write_err("' : not a valid identifier\n");
	}
	if (err == 17)
	{
		write_err("Minishell: ");
		write_err(str);
		write_err(": Builtin has no options.\n");
	}
}

void	ft_error(char *str, int err, int code)
{
	g_exit_code = code;
	if (err >= 0 && err < 10)
		write_err(str);
	if (err >= 0 && err < 10)
		exit(g_exit_code);
	if (err >= 11 && err <= 12)
		cd_err(str, err);
	if (err >= 14 && err <= 17)
		exec_err(str, err);
	if (err >= 20 && err < 30)
		syntax_err(str, err);
	if (err >= 30 && err < 40)
		redirect_err(str, err);
}
