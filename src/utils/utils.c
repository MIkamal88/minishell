/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:50:04 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/29 20:53:57 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	write_err(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		write(2, &str[i], 1);
}

void	exit_errno(char *errfile, int errnb)
{
	if (errnb == EACCES)
		ft_error(errfile, PERM_DENIED, 126);
	else if (errnb == ENOENT)
		ft_error(errfile, F_D_MIA, 1);
	else if (errnb == EISDIR)
		ft_error(errfile, IS_DIR, 126);
	else
		ft_error(errfile, CMD_MIA, 127);
}

void	exit_minishell(t_mini *minishell, int ret)
{
	ft_error("exit", EXIT_CMD, ret);
	clear(minishell);
	exit(g_exit_code);
}

void	free_arr(void **split_arr)
{
	int	i;

	i = -1;
	if (!split_arr)
		return ;
	while (split_arr[++i])
		free(split_arr[i]);
	free(split_arr);
}

char	**ft_arrdup(char **arr)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free_arr((void **)rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}
