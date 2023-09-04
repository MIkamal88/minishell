/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:14:00 by m_kamal           #+#    #+#             */
/*   Updated: 2023/08/31 14:14:01 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	terminate(t_mini *minishell, char *err)
{
	clear(minishell);
	printf("%s", err);
	exit(1);
}

void	exit_err(char *err)
{
	printf("%s", err);
	exit(1);
}
