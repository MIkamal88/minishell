/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:27:14 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/08 15:27:14 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	FT_EXPORT
**	---------
**	DESCRIPTION
**	Sets environment variables. If a variable already exists in the env list,
**	it will substitute it. If it exists in the local list, it will then remove
**	it from there and add it to the env. 
**	PARAMETERS
**	#1. The complete exec list of parameters.
**	RETURN VALUES
**	0 for sucess, 1 for error.
*/
