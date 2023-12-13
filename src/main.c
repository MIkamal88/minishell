/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:58:28 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/29 20:53:30 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_exit_code;

int	main(int argc, char **argv, char **envp)
{
	t_mini	*minishell;

	if (argc > 1 && argv)
		ft_error("This program doesn't accept arguments.\n", ARGS, 1);
	minishell = init_minishell(envp);
	open_terminal(minishell);
}
