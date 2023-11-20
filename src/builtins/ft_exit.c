/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:27:28 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/08 15:27:28 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_numberic(char *param)
{
	int	i;

	i = -1;
	while (param[++i])
	{
		if (!ft_isdigit(param[i]) && param[i] != '+' && param[i] != '-')
			return (0);
	}
	return (1);
}

int	ft_exit(char **exec)
{
	int	ret;

	ret = 0;
	if (exec[1] && exec[2])
	{
		ft_error("exit", 14, 1);
		return (1);
	}
	if (exec[1] && is_numberic(exec[1]))
	{
		ret = ft_atoi(exec[1]);
		if (ret < 0 || ret > 255)
			ret = 128;
	}
	ft_error("exit", 1, ret);
	return (0);
}
