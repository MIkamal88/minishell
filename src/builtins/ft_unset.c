/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:02:29 by anayef            #+#    #+#             */
/*   Updated: 2023/11/27 21:48:20 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_variable_in_list(t_env *env_list, char *variable)
{
	t_env	*current;

	current = env_list;
	while (current != NULL)
	{
		if (ft_strcmp(current->variable, variable) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

t_env	*find_variable_in_list(t_env *env_list, char *variable)
{
	t_env	*current;

	current = env_list;
	while (current != NULL && ft_strcmp(current->variable, variable) != 0)
		current = current->next;
	return (current);
}

void	remove_variable(t_env **env_list, t_env *variable_to_remove)
{
	t_env	*current;

	if (*env_list == variable_to_remove)
		*env_list = variable_to_remove->next;
	else
	{
		current = *env_list;
		while (current != NULL && current->next != variable_to_remove)
			current = current->next;
		if (current != NULL)
			current->next = variable_to_remove->next;
	}
	free(variable_to_remove->variable);
	free(variable_to_remove->value);
	free(variable_to_remove);
}

void	ft_unset(char **args, t_env **env_list)
{
	t_env	*variable_to_remove;
	int		i;

	i = 1;
	if (args[1] == NULL)
		return ;
	while (args[i] != NULL)
	{
		if (!is_variable_in_list(*env_list, args[i]))
			return ;
		variable_to_remove = find_variable_in_list(*env_list, args[i]);
		remove_variable(env_list, variable_to_remove);
		i++;
	}
}
