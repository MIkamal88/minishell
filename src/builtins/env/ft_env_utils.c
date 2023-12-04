/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:07:11 by anayef            #+#    #+#             */
/*   Updated: 2023/11/27 21:51:52 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	add_env(t_mini *minishell, char *key, char *value)
{
	t_env	*new;
	t_env	*ptr;

	ptr = minishell->env;
	new = malloc(sizeof(t_env));
	if (!new)
		ft_error(NULL, EXIT, 12);
	new->key = key;
	new->value = value;
	new->next = NULL;
	if (!minishell->env)
	{
		minishell->env = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

char	*get_env_name(char *arg)
{
	char	*name;
	int		len;

	if (!ft_strchr(arg, '='))
		len = ft_strlen(arg) + 1;
	else
		len = ft_strchr(arg, '=') - arg + 1;
	name = malloc(sizeof(char) * len);
	if (!name)
		ft_error(NULL, EXIT, 12);
	ft_strlcpy(name, arg, len);
	return (name);
}

char	*get_env_value(char *arg)
{
	char	*value;
	char	*ptr;
	int		len;

	ptr = ft_strchr(arg, '=');
	if (!ptr)
		return (NULL);
	ptr++;
	len = ft_strlen(ptr) + 1;
	value = malloc(sizeof(char) * len);
	if (!value)
		ft_error(NULL, EXIT, 12);
	ft_strlcpy(value, ptr, len);
	return (value);
}

t_env	*get_env(t_mini *minishell, char *key)
{
	t_env	*ptr;
	size_t	len;

	ptr = minishell->env;
	len = ft_strlen(key);
	while (ptr)
	{
		if (ft_strlen(ptr->key) == len && ft_strncmp(key, ptr->key, len) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_bool	is_valid_key(char *key)
{
	char	*ptr;

	ptr = key;
	if (((*key < 'a' || *key > 'z') && (*key < 'A'
				|| *key > 'Z')) && *key != '_')
		return (FALSE);
	while (*ptr && *ptr != '=')
	{
		if (((*ptr < 'a' || *ptr > 'z') && (*ptr < 'A' || *ptr > 'Z'))
			&& (*ptr != '_') && ((*ptr < '0' || *ptr > '9')))
			return (FALSE);
		ptr++;
	}
	return (TRUE);
}
