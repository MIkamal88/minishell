/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:52:15 by m_kamal           #+#    #+#             */
/*   Updated: 2023/08/24 18:52:16 by m_kamal          ###   ########.fr       */
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
# include "../libft/includes/libft.h"
# include "./colors.h"
# include "./parser.h"

enum	e_mini_err
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	TKN_ERR = 4,
	DUPERR = 7,
	FORKERR = 8,
	SYNT_ERR = 9,
	SYNT_ERR_2 = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13,
	ARGS = 14
};

typedef struct s_mini
{
	char		**envp;
	t_cmd		*cmd;
	t_parser	*parser;
}	t_mini;

typedef struct s_global
{
	int	exit_code;
}	t_global;

extern t_global	g_glob;

t_mini		*init_minishell(char **envp);
t_parser	*init_parser(void);

char		*get_pwd(void);
int			builtin_pwd(void);
char		*create_prompt(void);
void		open_terminal(t_mini *minishell);

void		tokenize_input(t_parser *parser);
int			lexical_analysis(char *token);
void		cmd_table(t_mini *minishell);
t_cmd		*cmd_create(int id);
void		cmd_add_back(t_mini *minishell, t_cmd *node);

void		ft_error(char *s, int err, int code);
void		terminate(t_mini *minishell);
void		exit_err(char *err);
void		clear(t_mini *minishell);
void		clear_parser(t_parser *parser);
void		clear_cmd(t_cmd *cmd);

char		**ft_arrdup(char **arr);
char		*ft_strnjoin(int argn, ...);
void		free_arr(char **split_arr);

#endif
