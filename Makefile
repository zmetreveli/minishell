# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 01:10:05 by zmetreve          #+#    #+#              #
#    Updated: 2025/04/08 09:38:02 by zmetreve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = minishell.c \
	  src/builtins/cd.c \
	  src/builtins/echo.c \
	  src/builtins/env.c \
	  src/builtins/exit.c \
	  src/builtins/export.c \
	  src/builtins/pwd.c \
	  src/builtins/unset.c \
	  src/executor/exec.c \
	  src/executor/redir.c \
	  src/parser/lexer.c \
	  src/parser/parcer.c

OBJ = $(SRC:.c=.o)



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re