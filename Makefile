# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 01:10:05 by zmetreve          #+#    #+#              #
#    Updated: 2025/06/22 00:27:47 by zmetreve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/minishell.c \
	  src/builtins/cd.c \
	  src/builtins/echo.c \
	  src/builtins/env.c \
	  src/builtins/exit.c \
	  src/builtins/export.c \
	  src/builtins/pwd.c \
	  src/builtins/unset.c \
	  src/env/env_utils.c \
	  src/env/env.c \
	  src/parser/args_echo_utils.c \
	  src/parser/args_echo.c \
	  src/parser/args.c \
	  src/parser/commands.c \
	  src/parser/heredoc_utils.c \
	  src/parser/heredoc.c \
	  src/parser/parce_word.c \
	  src/parser/parcer.c \
	  src/parser/parse_append.c \
	  src/parser/parse_input.c \
	  src/parser/parcer.c \
	  src/parser/test.c \
	  src/parser/trunc.c \
	  src/redirection/redirection.c \
	  src/clean_and_exit/exit.c \
	  src/clean_and_exit/error.c \
	  src/clean_and_exit/free.c \
	  src/executor/exec.c \
	  src/lexer/parse_user_input.c \
	  src/utils/init_data.c \
	  src/signal/signal.c \
	  src/expantion/var_expander.c \

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ../libft
LIBFT = ../libft/libft.a

all: $(NAME)

%.o: %.c includes/builtins.h includes/parser.h includes/redirection.h includes/env.h includes/clean_and_exit.h $(LIBFT) Makefile \
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(OBJ) $(SRC) Makefile includes/builtins.h includes/parser.h includes/redirection.h includes/clean_and_exit.h includes/env.h \
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re