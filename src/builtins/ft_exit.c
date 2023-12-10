/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:27:28 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/08 15:27:28 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	FT_EXIT
 *	-------
 *	DESCRIPTION
 *	Exits minishell in a similar fashion to bash
 *	if a valid value is entered, it'll be used as
 *	exit code.
 *	PARAMETERS
 *	#1. Complete exec list of parameters.
 *	RETURN VALUES
 *	-
*/

static int	is_numeric(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '+' && arg[i] != '-')
			return (0);
	}
	return (1);
}

int	ft_exit(char **exec, t_mini *minishell)
{
	int	ret;

	ret = 0;
	if (exec[1] && exec[2])
	{
		ft_error("exit", 14, 1);
		return (1);
	}
	if (exec[1] && is_numeric(exec[1]))
	{
		ret = ft_atoi(exec[1]);
		if (ret < 0 || ret > 255)
			ret = 128;
	}
	if (exec[1] && !is_numeric(exec[1]))
	{
		ret = 2;
		write_err("Minishell: exit: ");
		write_err(exec[1]);
		write_err(": numeric argument required\n");
	}
	exit_minishell(minishell, ret);
	return (0);
}
