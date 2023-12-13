/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:31:06 by m_kamal           #+#    #+#             */
/*   Updated: 2023/11/27 21:21:37 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*	FT_CD
 *	-----
 *	DESCRIPTION
 *	Changes Current directory to a specified one
 *	PARAMETERS
 *	#1. Complete exec list of parameters
 *	RETURN VALUES
 *	-
*/

static char	**create_export_exec(char *pwd, char *oldpwd)
{
	char	**exec;
	char	*name;

	exec = ft_calloc(4, sizeof(char *));
	if (!exec)
		ft_error(NULL, EXIT, 12);
	name = ft_strdup("export");
	exec[0] = name;
	exec[1] = pwd;
	exec[2] = oldpwd;
	return (exec);
}

static int	cd_cmd(t_mini *minishell, char *path)
{
	char	*oldpwd;
	char	*pwd;
	char	*curr_pwd;
	char	**exec;

	if (chdir(path) == -1)
	{
		ft_error(path, CD_NO_F_OR_D, 1);
		return (1);
	}
	oldpwd = ft_strjoin("OLDPWD=", key_search(minishell->env, "PWD"));
	curr_pwd = get_pwd();
	pwd = ft_strjoin("PWD=", curr_pwd);
	free(curr_pwd);
	exec = create_export_exec(pwd, oldpwd);
	ft_export(minishell, exec);
	free_arr((void **)exec);
	return (0);
}

static int	cd_variable(t_mini *minishell, char *variable)
{
	char	*path;
	int		ret;

	path = key_search(minishell->env, variable);
	ret = 1;
	if (!path || !*path)
		ft_error(variable, CD_NOT_SET, 1);
	else
	{
		if (!ft_strncmp("OLDPWD", variable, 6))
			printf("%s\n", path);
		ret = cd_cmd(minishell, path);
	}
	return (ret);
}

int	ft_cd(t_mini *minishell, char **exec)
{
	char	*parameter;
	int		ret;	

	parameter = exec[1];
	ret = 1;
	if (parameter && exec[2])
		ft_error("cd", CMD_ARGS, 1);
	else if (!parameter || !*parameter)
		ret = cd_variable(minishell, "HOME");
	else if (!ft_strncmp(parameter, "-", 2))
		ret = cd_variable(minishell, "OLDPWD");
	else
		ret = cd_cmd(minishell, parameter);
	return (ret);
}
