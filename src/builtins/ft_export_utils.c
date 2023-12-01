/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:07:11 by anayef            #+#    #+#             */
/*   Updated: 2023/11/27 21:51:52 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*create_env_node(const char *variable, const char *value)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (new_node)
	{
		new_node->variable = ft_strdup(variable);
		new_node->value = ft_strdup(value);
		new_node->next = NULL;
	}
	return (new_node);
}

void	add_env_variable(t_env **env_list, const char *variable,
	const char *value)
{
	t_env	*new_node;

	new_node = create_env_node(variable, value);
	if (new_node)
	{
		new_node->next = *env_list;
		*env_list = new_node;
	}
}

void	free_env_list(t_env *env_list)
{
	t_env	*temp;

	while (env_list)
	{
		temp = env_list;
		env_list = env_list->next;
		free(temp->variable);
		free(temp->value);
		free(temp);
	}
}

void	handle_export_without_arguments(t_env *env_list)
{
	t_env	*current;

	current = env_list;
	while (current != NULL)
	{
		printf("%s=\"%s\"\n", current->variable, current->value);
		current = current->next;
	}
}

void	handle_export_with_argument(char **args, t_env **env_list)
{
	char	*variable;
	char	*value;

	variable = get_variable_from_argument(args[1]);
	value = get_value_from_argument(args[1]);
	if (ft_strcmp(value, "") == 0)
	{
		free(variable);
		printf("Invalid format for 'export'\n");
		return ;
	}
	update_env_value(*env_list, variable, value);
	add_env_variable(env_list, variable, value);
	free(variable);
}
