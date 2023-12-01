/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:27:14 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/27 21:56:26 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_value_from_argument(char *arg)
{
	char	*value;
	int		len;
	int		i;

	i = 0;
	value = "";
	len = ft_strlen(arg);
	while (i < len)
	{
		if (arg[i] == '=')
		{
			value = &arg[i + 1];
			break ;
		}
		i++;
	}
	return (value);
}

char	*get_variable_from_argument(char *arg)
{
	char	*variable;
	int		len;
	int		i;

	i = 0;
	variable = ft_strdup(arg);
	len = ft_strlen(arg);
	while (i < len)
	{
		if (arg[i] == '=')
		{
			variable[i] = '\0';
			break ;
		}
		i++;
	}
	return (variable);
}

void	update_env_value(t_env *env_list, char *variable, char *new_value)
{
	t_env	*current;

	current = env_list;
	while (current != NULL)
	{
		if (ft_strcmp(current->variable, variable) == 0)
		{
			free(current->value);
			current->value = ft_strdup(new_value);
			return ;
		}
		current = current->next;
	}
}

void	builtin_export(char **args, t_env **env_list)
{
	if (args[1] == NULL)
		handle_export_without_arguments(*env_list);
	else
		handle_export_with_argument(args, env_list);
}
