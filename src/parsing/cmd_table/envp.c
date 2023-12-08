/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:39:11 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/08 09:39:11 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	get_count(t_env *env)
{
	int		count;

	count = 0;
	while (env)
	{
		count++;
		env = env->next;
	}
	return (count);
}

/*	CREATE_ENVP
 *	-----------
 *	Purpose of this function is to create an updated envp
 *	as per our t_env structured list in order to pass it along
 *	for execve, saved inside the t_cmd struct.
*/

char	**create_envp(t_env *env)
{
	char	**envp;
	char	*tmp;
	int		count;
	int		i;

	i = 0;
	count = get_count(env);
	envp = ft_calloc(count + 1, sizeof(char *));
	if (!envp)
		ft_error(NULL, EXIT, 12);
	while (env && env->value)
	{
		tmp = ft_strjoin(env->key, "=");
		envp[i] = ft_strjoin(tmp, env->value);
		free(tmp);
		env = env->next;
		i++;
	}
	return (envp);
}
