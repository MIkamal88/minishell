/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anayef <anayef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:52:15 by m_kamal           #+#    #+#             */
/*   Updated: 2023/12/08 21:11:26 by anayef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# include "./colors.h"
# include "./parser.h"

# define MAX_PID	1024

enum	e_mini_err
{
	EXIT = 0,
	ARGS = 1,
	EXIT_CMD = 2,
	EXIT_HEREDOC_SIG = 3,
	CD_NOT_SET = 11,
	CD_NO_F_OR_D = 12,
	CMD_ARGS = 14,
	CMD_MIA = 15,
	EXPORT = 16,
	NO_OPTN = 17,
	SYNT_ERR_TOKEN = 21,
	QUOTE_MIA = 22,
	PERM_DENIED = 31,
	F_D_MIA = 32,
	HERE_DOC_EOF = 33,
	QUIT = 34,
	NEW_L = 35,
};

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

typedef struct s_mini
{
	t_cmd		*cmd;
	t_env		*env;
	t_parser	*parser;
}	t_mini;

extern int	g_exit_code;

// Initialization
t_mini		*init_minishell(char **envp);
t_parser	*init_parser(void);
char		*create_prompt(void);
void		run_signals(void);
void		open_terminal(t_mini *minishell);

// Command Table
void		cmd_table(t_mini *minishell);
void		cmd_list(t_mini *minishell);
void		cmd_expansion(t_mini *minishell);
t_cmd		*cmd_create(int id);
void		cmd_add_back(t_cmd **cmd, t_cmd *last);

// ENV Struct
char		**create_envp(t_env *env);
t_env		*get_env(t_mini *minishell, char *key);
char		*get_env_name(char *arg);
char		*get_env_value(char *arg);
t_bool		check_params(char *argv);
t_bool		is_valid_key(char *key);
char		*key_search(t_env *env, char *key);
void		tilde_expansion(t_env *env, t_token **token, int *pos);
void		quote_expansion(t_env *env, t_token **token, int *pos, char quote);
void		variable_expansion(t_env *env, t_token **tkn, int *pos);
t_env		*create_env_node(const char *variable, const char *value);
void		add_env_variable(t_env **env_list, \
	const char *variable, const char *value);
void		exec_export(t_mini *minishell, char *exec);
void		envp_swap(t_mini *minishell, t_cmd *cmd);

// Execution
void		exec_line(t_mini *minishell);
void		exec_cmds(t_mini *minishell);
void		exec_cmd(t_mini *minishell);
void		setup_pipes(t_mini *minishell);
void		setup_cmd(t_mini *minishell, t_cmd **ptr);
void		wait_all(int pid[MAX_PID], int id);
void		dup2_close_fds(t_cmd *cmd);
int			define_redirects(t_mini *minishell);
void		exec_builtin(char **args, t_mini *minishell);
void		exec_pipe_block(t_mini *minishell);
void		exec_cmd(t_mini *minishell);
t_bool		is_forked(t_mini *minishell);
void		assign_word(t_mini *minishell);
void		exec_builtin_child(t_mini *minishell);
void		exec_builtin_parent(t_mini *minishell);
void		close_fd(t_cmd *cmd, int flag);
void		close_fds(t_cmd *cmd);
char		*fetch_path(t_cmd *cmd, t_env *env);
void		exec_cmd_child_sig(void);
void		exec_cmd_parent_sig(void);

// Builtins
int			ft_env(t_mini *minishell, char **exec);
int			ft_export(t_mini *minishell, char **exec);
int			ft_unset(t_mini *minishell, char **exec);
void		add_env(t_mini *minishell, char *key, char *value);
int			ft_exit(char **exec, t_mini *minishell);
char		*get_pwd(void);
int			ft_pwd(void);
int			ft_cd(t_mini *minishell, char **exec);
int			ft_echo(char **args);
void		assign_word(t_mini *minishell);
int			is_builtin(char *command);

// Exit
void		ft_error(char *str, int err, int code);
void		write_err(char *str);
void		exit_errno(char *errfile, int errnb);
void		clear(t_mini *minishell);
void		clear_parser(t_mini *minishell);
void		clear_cmd(t_cmd **cmd);
void		clear_env(t_mini *minishell);
void		exit_minishell(t_mini *minishell, int ret);

// Utils
char		**ft_arrdup(char **arr);
char		*ft_strnjoin(int argn, ...);
void		free_arr(void **split_arr);

#endif
