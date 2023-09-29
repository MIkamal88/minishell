/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:03:21 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/25 22:03:21 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*	TILDE_EXPANSION
**	---------------
**	DESCRIPTION
**	It expands the tilde symbol into a full home directory path, using the HOME 
**	environment variable.
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no tilde expansion was found.
*/
