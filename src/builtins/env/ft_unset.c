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

#include "../../../include/minishell.h"

void	remove_env(t_mini *minishell, t_env *target)
{
	t_env	*tmp;

	tmp = minishell->env;
	if (tmp == target)
		minishell->env = tmp->next;
	else
	{
		while (tmp->next != target)
			tmp = tmp->next;
		tmp->next = target->next;
	}
	free(target->key);
	free(target->value);
	free(target);
}

int	ft_unset(t_mini *minishell, char **exec)
{
	t_env	*target;

	if (!*(exec + 1))
		return (0);
	exec++;
	while (*exec)
	{
		if (check_params(*exec))
			ft_error(*exec, 14, 1);
		else
		{
			target = get_env(minishell, *exec);
			if (target)
				remove_env(minishell, target);
		}
		exec++;
	}
	return (0);
}
