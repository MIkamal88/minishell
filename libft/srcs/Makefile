# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:27:21 by mshehata          #+#    #+#              #
#    Updated: 2022/12/03 14:03:04 by mshehata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Library = libft

PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
			ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
			ft_calloc.c ft_strdup.c\

PART2 = ft_striteri.c ft_strmapi.c ft_putchar_fd.c ft_putendl_fd.c ft_split.c\
		ft_putstr_fd.c ft_strjoin.c ft_strtrim.c ft_substr.c ft_putnbr_fd.c\
		ft_itoa.c get_next_line.c\


CC = gcc

FLAGS = -Wall -Wextra -Werror -c

OUTN = $(Library).a

SRC = $(PART1) $(PART2)

OFILES = $(SRC:.c=.o)

NAME = $(OUTN)

$(NAME):
		$(CC) $(FLAGS) $(SRC) -I./
		ar -rc $(OUTN) $(OFILES)

all: $(NAME)

clean:
	@rm -f $(OFILES)

fclean:	clean
		@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

.SILENT:	$(NAME)	$(OBJ)
