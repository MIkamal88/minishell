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
**	0 for sucess, 1 for error.
*/

int	ft_echo(char **exec)
{
	char	*flag;
	int		i;

	flag = NULL;
	i = 1;
	if (exec[i] && *exec[i] == '-')
		flag = &exec[i++][1];
	while (exec[i])
	{
		printf("%s", exec[i++]);
		if (exec[i])
			printf(" ");
	}
	if (ft_strncmp(flag, "n\0", 2))
		printf("\n");
	return (0);
}
