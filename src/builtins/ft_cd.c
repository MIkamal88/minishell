/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:31:06 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/27 21:21:37 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	FT_CD
 *	-----
 *	DESCRIPTION
 *	Changes Current directory to a specified one
 *	PARAMETERS
 *	#1. Complete exec list of parameters
 *	RETURN VALUES
 *	-
 *	FT_PWD
 *	------
 *	DESCRIPTION
 *	Prints Current Directory
 *	PARAMETERS
 *	-
 *	RETURN
 *	-
*/

char	*get_pwd(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}

void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		printf("%s\n", cwd);
		free(cwd);
	}
	else
		return ;
}

void	ft_cd(char **exec)
{
	if (exec[1] == NULL)
		return ;
	else
	{
		if (exec[1] && exec[2])
			ft_error("cd", 14, 1);
		else if (check_params(exec[1]))
			ft_error(*exec, 17, 1);
		else if (chdir(exec[1]) != 0)
			ft_error(exec[1], 12, 1);
	}
}
