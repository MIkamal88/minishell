/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 08:05:07 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/01 08:05:07 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_mini	*init_minishell(char **envp)
{
	t_mini	*minishell;

	minishell = malloc(sizeof(t_mini));
	if (!minishell)
		terminate(minishell, "Error initializing Minishell");
	minishell->envp = ft_arrdup(envp);
	minishell->parser = init_parser();
	if (!minishell->parser)
		terminate(minishell, "Error initializing Parser");
	return (minishell);
}
