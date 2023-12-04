/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:06:06 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/27 21:28:02 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char *command)
{
	if (ft_strcmp(command, "echo") == 0
		|| ft_strcmp(command, "pwd") == 0
		|| ft_strcmp(command, "cd") == 0
		|| ft_strcmp(command, "export") == 0
		|| ft_strcmp(command, "unset") == 0
		|| ft_strcmp(command, "env") == 0
		|| ft_strcmp(command, "exit") == 0)
		return (1);
	return (0);
}
