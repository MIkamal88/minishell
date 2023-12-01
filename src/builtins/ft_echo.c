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

void	builtin_echo(char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		printf("%s", args[i]);
		if (args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
}
