/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:02:59 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/04 20:02:59 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	env_quotes(t_mini *minishell)
{
	t_env	*ptr;

	ptr = minishell->env;
	while (ptr)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(ptr->key, STDOUT_FILENO);
		if (ptr->value)
		{
			write(STDOUT_FILENO, "=\"", 2);
			ft_putstr_fd(ptr->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\"", 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		ptr = ptr->next;
	}
}

static void	exec_export(t_mini *minishell, char *exec)
{
	char	*name;
	char	*value;
	t_env	*ptr;

	name = get_env_name(exec);
	value = get_env_value(exec);
	ptr = get_env(minishell, name);
	if (ptr)
	{
		if (value)
		{
			if (ptr->value)
				free(ptr->value);
			ptr->value = value;
		}
		free(name);
	}
	else
		add_env(minishell, name, get_env_value(exec));
	free(value);
}

int	ft_export(t_mini *minishell, char **exec)
{
	if (!exec[1])
	{
		env_quotes(minishell);
		return (0);
	}
	exec++;
	while (*exec)
	{
		if (check_params(*exec))
			ft_error(*exec, 14, 1);
		else if (!is_valid_key(*exec))
			ft_error(*exec, 16, 1);
		else
			exec_export(minishell, *exec);
		exec++;
	}
	return (0);
}
