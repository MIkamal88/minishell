/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 07:33:54 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/08 19:56:51 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "parser.h"
# define MAX_PID	1024

enum e_fd{
	IN,
	OUT,
	BOTH,
};

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

char	**create_envp(t_env *env);
t_bool	check_params(char *argv);
t_bool	is_valid_key(char *key);
int		is_forked(t_cmd *cmd);
void	handle_export_with_argument(char **args, t_env **env_list);
void	handle_export_without_arguments(t_env *env_list);
char	*get_value_from_argument(char *arg);
char	*get_variable_from_argument(char *arg);

void	update_env_value(t_env *env_list, char *variable, char *new_value);

char	*get_pwd(void);
void	ft_pwd(void);
void	ft_cd(char **exec);
int		ft_echo(char **args);
void	exec_external_cmd(char **args, char **envp);
char	*build_executable_path(char *dir, char *cmd);
char	**get_directories_from_path(void);
int		is_builtin(char *command);

t_env	*create_env_node(const char *variable, const char *value);
void	add_env_variable(t_env **env_list, \
	const char *variable, const char *value);
void	free_env_list(t_env *env_list);

void	exec_builtin_in_child(t_cmd *cmd);
void	exec_builtin_in_parent(t_cmd *cmd);
void	close_fd(int fd);

void	change_exec(t_cmd *cmd, int pos);
void	assign_word(t_cmd *cmd);

void	close_fds(t_cmd *cmd);
// void	close_fd(t_cmd *cmd, int flag);

char	*get_path(t_cmd *cmd);
void	exec_commands_child_signals(void);
void	exec_commands_parent_signals(void);

#endif
