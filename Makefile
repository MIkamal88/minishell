NAME	= minishell
LIBFT	= libft.a

CC	= gcc -g
CF	= -Wall -Wextra -Werror #-fsanitize=address
CFI	= -I $(INCLUDE)
CREADLINE	= -lreadline

LIBFT_PATH	= ./libft/
SRC_PATH		= ./src/
OBJ_PATH		= ./build/
INCLUDE			= ./include/

SRC	= main.c\
			init_minishell.c\
			open_terminal.c\
			prompt.c\
			signals.c\
			clear.c\
			errors.c\
			utils.c\
			lexer.c\
			token_utils.c\
			token_utils2.c\
			tokenizer.c\
			syntax_analysis.c\
			syntax_checks.c\
			cmd_list.c\
			cmd_table.c\
			cmd_utils.c\
			envp.c\
			cmd_expansion.c\
			quote_expansion.c\
			tilde_expansion.c\
			variable_expansion.c\
			exec_line.c\
			exec_pipe_block.c\
			fetch_path.c\
			exec_builtin.c\
			pipes_redirects.c\
			close_fds.c\
			cmd_sigs.c\
			ft_pwd.c\
			ft_cd.c\
			ft_echo.c\
			ft_env.c\
			ft_exit.c\
			ft_export.c\
			ft_env_utils.c\
			ft_unset.c\
			is_builtin.c\
			check_params.c\

VPATH	:= $(SRC_PATH)\
 			$(SRC_PATH)utils\
 			$(SRC_PATH)parsing\
 			$(SRC_PATH)execute\
			$(SRC_PATH)builtins\
			$(SRC_PATH)builtins/env\
 			$(SRC_PATH)parsing/syntax\
 			$(SRC_PATH)parsing/cmd_table\
 			$(SRC_PATH)system\

OBJ = $(addprefix $(OBJ_PATH), $(notdir $(SRC:.c=.o)))

RM = rm -rf


$(OBJ_PATH)%.o: %.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CF) $(CFI) -c $< -o $@

$(NAME):	ANNOUNCE $(OBJ)
	@printf "$(GR)Objects ready!$(RC)\n"
	@printf "$(YE)Compiling LibFT...$(RC)\n"
	@make --no-print-directory -C $(LIBFT_PATH) $(LIBFT)
	@printf "$(CY)Compiling Minishell Executable...$(RC)\n"
	$(CC) $(CF) -I $(INCLUDE) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft $(CREADLINE)
	@printf "$(GR)Done!$(RC)\n"

all:	$(NAME)

ANNOUNCE:
	@printf "$(YE)Generating Object Files...$(RC)\n"

re:		fclean all

clean:
	@make --no-print-directory -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ) $(OBJ_PATH)
	@printf "$(RE)Object Files Removed!$(RC)\n"

fclean:	clean
	@make --no-print-directory -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@printf "$(RE)Executable Removed!$(RC)\n"

leak:	all
	valgrind --suppressions=./valgrind.txt --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY:		all clean fclean re

.SILENT:	$(NAME)	$(OBJ)

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m
