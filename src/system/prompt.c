/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:25:13 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/22 21:44:14 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*create_prompt(void)
{
	char	*prog_name;
	char	*folder;
	char	*folder_u;
	char	*second_half;
	char	*result;

	prog_name = ft_strjoin(ESC_GREEN, "xXBashXx\001\033[0m\002:");
	folder = get_pwd();
	folder_u = ft_strjoin(ESC_BLUE, folder);
	second_half = ft_strjoin(folder_u, "\001\033[0m\002\n$ ");
	result = ft_strjoin(prog_name, second_half);
	free(prog_name);
	free(folder);
	free(folder_u);
	free(second_half);
	return (result);
}
