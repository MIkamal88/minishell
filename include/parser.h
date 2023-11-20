/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:48:32 by m_kamal           #+#    #+#             */
/*   Updated: 2023/08/31 15:48:32 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum s_lex
{
	WORD,
	ASSIGN_WORD,
	LESS,
	DLESS,
	GREAT,
	DGREAT,
	PIPE,
}	t_lex;

typedef struct s_token
{
	int				lexema;
	char			*tkn;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	int				id;
	t_token			*commands;
	t_token			*redirects;
	int				endpoint;
	int				is_piped;
	char			**exec;
	char			*exec_path;
	char			**envp;
	int				fd_in;
	int				fd_out;
	int				fd_pipe[2];
	int				errnb;
	char			*errfile;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_parser
{
	char	*input;
	t_token	*tokens;
}	t_parser;

# define METACHAR	"|<>&()"
# define METACHARS	"|<>&() "

t_token		*create_token(char *tkn, int flag);
void		tokenize_input(t_parser *parser);
int			lexical_analysis(char *token);
void		token_add_back(t_token **list, t_token *token);
t_bool		is_new_token(const char *input, int index, int prev);
t_token		*tkn_dup(t_token *original);
int			tkn_len(t_token *token);

t_cmd		*cmd_create(char **envp, int id);
void		cmd_add_back(t_cmd **cmd, t_cmd *last);
void		cmd_expansion(t_cmd *cmd);
void		swap_token(t_token *token, char	*new_token);
void		tilde_expansion(t_token **token, int *pos);
void		quote_expansion(t_token **token, int *pos, char quote);
void		variable_expansion(t_token **tkn, int *pos);

t_bool		syntax_analysis(t_parser *parser);
int			is_assign_word(char *token);
t_bool		syntax_pipe(t_token *token, int pos);
t_bool		syntax_redirect_io(t_token *token);
t_bool		syntax_quote(t_token *token);

#endif
