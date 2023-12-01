/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:07:22 by anayef            #+#    #+#             */
/*   Updated: 2023/11/27 21:31:20 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_env(t_env **env_list)
{
	t_env	*current;

	current = *env_list;
	while (current != NULL)
	{
		printf("%s=%s\n", current->variable, current->value);
		current = current->next;
	}
}
