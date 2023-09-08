NAME	= minishell
LIBFT	= libft.a

CC	= gcc
CF	= -Wall -Wextra -Werror -g
CFI	= -I $(INCLUDE)
CREADLINE	= -lreadline

LIBFT_PATH	= ./libft/srcs/
SRC_PATH		= ./src/
OBJ_PATH		= ./build/
INCLUDE			= ./include/

SRC	= main.c\
			prompt.c\
			open_terminal.c\
			init_minishell.c\
			init_parser.c\
			errors.c\
			utils.c\
			clear.c\
			builtin_pwd.c\
			lexer.c\
			token_utils.c\
			tokenizer.c\

VPATH	:= $(SRC_PATH)\
			$(SRC_PATH)builtins\
 			$(SRC_PATH)utils\
 			$(SRC_PATH)parsing\
 			$(SRC_PATH)parsing/lexical_analyzer\
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
	@printf "$(YE)Generating .o Files...$(RC)\n"

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
	valgrind --suppressions=./local.supp --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY:		all clean fclean re

.SILENT:	$(NAME)	$(OBJ)

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m
