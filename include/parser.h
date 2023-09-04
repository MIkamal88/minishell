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

typedef enum s_tokens
{
	PIPE,
	GREAT,
	DGREAT,
	LESS,
	DLESS,
}	t_tokens;

typedef struct s_parser
{
	char	*input;
}	t_parser;

t_parser	*init_parser(void);

#endif
