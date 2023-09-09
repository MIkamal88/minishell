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
	PIPE,
	LESS,
	DLESS,
	GREAT,
	DGREAT,
	PARANTHESIS,
}	t_lex;

typedef struct s_token
{
	int				lexema;
	char			*tkn;
	struct s_token	*next;
}	t_token;

typedef struct s_simp_cmd
{
	char	*exec;
	char	*exec_path;
	int		num_args;
	char	**args;
}	t_simp_cmd;

typedef struct s_cmd
{
	int			num_simp_cmd;
	t_simp_cmd	**simp_cmds;
}	t_cmd;

typedef struct s_parser
{
	char	*input;
	t_token	*tokens;
}	t_parser;

# define METACHAR	"|<>&()"
# define METACHARS	"|<>&() "

t_parser	*init_parser(void);
void		tokenize_input(t_parser *parser);
int			lexical_analysis(char *token);
t_token		*create_token(char *tkn);
void		token_add_back(t_token **list, t_token *token);
t_bool		is_new_token(const char *input, int index, int prev);

t_bool		syntax_analysis(t_parser *parser);
t_bool		syntax_pipe(t_token *token, int pos);
t_bool		syntax_redirect_io(t_token *token);
t_bool		syntax_quote(t_token *token);

#endif
