/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:56:23 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/26 11:56:23 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	tkn_len(t_token *token)
{
	int	len;

	len = 0;
	while (token)
	{
		len++;
		token = token->next;
	}
	return (len);
}
