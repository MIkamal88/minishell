/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:32:45 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/26 12:32:45 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	EXEC_LINE
**	---------
**	DESCRIPTION
**	It's a workflow for the execution of all commands passed by the user through
**	the prompt line. It first opens all the pipes, and then it reads and applies
**	the redirects and heredocs.
**	Lastly, it executes the commands by priority indentation.
**	PARAMETERS
**	Minishell
**	RETURN VALUES
**	-
*/

void	exec_line(t_mini *minishell)
{
	open_pipes(minishell);
	/* if (!define_redirects()) */
	/* 	return ; */
	/* exec_commands(); */
}
