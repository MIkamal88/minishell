/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:28:01 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/27 21:28:51 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	FT_ECHO
**	-------
**	DESCRIPTION
**	Prints the parameter into the directory.
**	PARAMETERS
**	#1. The complete exec list of parameters.
**	RETURN VALUES
**	0 for success, 1 for error.
*/

static int	check_echo_option(char *option)
{
	int	flag;
	int	i;

	flag = 0;
	i = 2;
	if (!ft_strncmp(option, "-n", i))
	{
		while (option[i] == 'n')
			i++;
		if (option[i])
			flag = 0;
		else
			flag = 1;
	}
	return (flag);
}

int	ft_echo(char **exec)
{
	int	flag;

	flag = 0;
	exec++;
	while (check_echo_option(*exec))
	{
		flag = 1;
		exec++;
	}
	while (*exec)
	{
		ft_putstr_fd(*exec, STDOUT_FILENO);
		if (*(exec + 1))
			ft_putstr_fd(" ", STDOUT_FILENO);
		exec++;
	}
	if (!flag)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
