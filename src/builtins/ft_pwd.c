/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 07:19:45 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/11 07:19:45 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
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

int	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		printf("%s\n", cwd);
		free(cwd);
		return (0);
	}
	else
		return (1);
}
