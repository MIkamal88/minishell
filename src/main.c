/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:58:28 by m_kamal           #+#    #+#             */
/*   Updated: 2023/08/24 18:58:29 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_exit_code;

int	main(int argc, char **argv, char **envp)
{
	t_mini	*minishell;

	if (argc > 1 && argv)
		ft_error("This program doesn't accept arguments.\n", 1, 1);
	minishell = init_minishell(envp);
	open_terminal(minishell);
}
