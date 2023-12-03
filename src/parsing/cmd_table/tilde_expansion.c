/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:03:21 by m_kamal           #+#    #+#             */
/*   Updated: 2023/09/25 22:03:21 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../../include/minishell.h"

/*	TILDE_EXPANSION
**	---------------
**	DESCRIPTION
**	It expands the tilde symbol into a full home directory path, using the HOME
**	environment variable.
**	PARAMETERS
**	#1. The token to expand.
**	RETURN VALUES
**	The expanded string, if appliable. NULL if no tilde expansion was found.
*/

// static int	is_tilde_expandable(char *home, char *parameter)
// {
// 	char	*logname;
// 	int		login_len;
//
// 	logname = &ft_strrchr(home, '/')[1];
// 	login_len = ft_strlen(logname);
// 	if (!parameter || *parameter == '/')
// 		return (1);
// 	if (!ft_strncmp(parameter, logname, login_len))
// 		if (parameter[login_len] == 0 || parameter[login_len] == '/')
// 			return (1);
// 	return (0);
// }
//
// static char	*expand_tilde(char	*home, char *parameter, int *pos)
// {
// 	char	*logname;
// 	char	*result;
//
// 	logname = &ft_strrchr(home, '/')[1];
// 	if (!parameter)
// 		result = ft_strdup(home);
// 	else if (!ft_strncmp(parameter, logname, ft_strlen(logname)))
// 		result = ft_strjoin(home, &parameter[ft_strlen(logname)]);
// 	else
// 		result = ft_strjoin(home, parameter);
// 	*pos = ft_strlen(home);
// 	return (result);
// }
//
// void	tilde_expansion(t_token **tkn, int *pos)
// {
// 	char	*home;
// 	char	*parameter;
//
// 	home = key_search("HOME");
// 	if (!home)
// 		return ;
// 	parameter = NULL;
// 	if ((*tkn)->tkn[(*pos) + 1])
// 		parameter = ft_strdup(&(*tkn)->tkn[(*pos) + 1]);
// 	if (is_tilde_expandable(home, parameter))
// 		swap_token(*tkn, expand_tilde(home, parameter, pos));
// 	if (parameter)
// 		free(parameter);
// }
