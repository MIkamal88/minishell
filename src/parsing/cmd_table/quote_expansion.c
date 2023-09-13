/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 07:11:49 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/13 07:11:49 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*	QUOTE_EXPANSION
**	---------------
**	DESCRIPTION
**	It expands the token in which there are quotation marks (either "" or ''), 
**	as well as any possible variables ($VAR) within "".
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no quotation was found.
*/

void	quote_expansion(t_token **tkn, int *pos, char quote)
{
	
}
