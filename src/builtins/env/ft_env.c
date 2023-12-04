/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:07:22 by anayef            #+#    #+#             */
/*   Updated: 2023/11/27 21:31:20 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*	DESCRIPTION
**	Prints the envp complete list of environment variables.
**	PARAMETERS
**	#1. The complete exec list of parameters.
**	RETURN VALUES
**	-
*/

int	ft_env(t_mini *minishell, char **exec)
{
	t_env	*ptr;

	ptr = minishell->env;
	if (*(exec + 1))
		ft_error("env", 14, 127);
	while (ptr)
	{
		if (ptr->value)
		{
			ft_putstr_fd(ptr->key, STDOUT_FILENO);
			ft_putchar_fd('=', STDOUT_FILENO);
			ft_putstr_fd(ptr->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\n", 1);
		}
		ptr = ptr->next;
	}
	return (0);
}
