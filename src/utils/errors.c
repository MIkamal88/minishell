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

void	terminate(t_mini *minishell)
{
	clear(minishell);
	exit(g_glob.exit_code);
}

void	exit_err(char *err)
{
	printf("%s", err);
	exit(1);
}

void	syntax_error(char *s, int err)
{
	if (err == SYNT_ERR)
		write(2, &s, ft_strlen(s));
}

void	ft_error(char *s, int err, int code)
{
	g_glob.exit_code = code;
	if (err == SYNT_ERR || err == SYNT_ERR_2)
		syntax_error(s, err);
}
