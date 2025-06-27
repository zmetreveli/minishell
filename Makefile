# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 01:10:05 by zmetreve          #+#    #+#              #
#    Updated: 2025/06/27 18:19:50 by zmetreve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Werror -Wextra -Wall -gdwarf-4 -g
CPPFLAGS += -I/opt/homebrew/opt/readline/include -I../MINISHELL/libft
LDFLAGS  += -L/opt/homebrew/opt/readline/lib
LIBS     += -lreadline

SRC = src/minishell.c \
	  src/builtins/cd.c \
	  src/builtins/echo.c \
	  src/builtins/env.c \
	  src/builtins/exit.c \
	  src/builtins/export.c \
	  src/builtins/pwd.c \
	  src/builtins/unset.c \
	  src/clean_and_exit/exit.c \
	  src/clean_and_exit/error.c \
	  src/clean_and_exit/free.c \
	  src/env/env_utils.c \
	  src/env/env.c \
	  src/executor/exec.c \
	  src/executor/exec_cmd.c \
	  src/executor/redir.c \
	  src/expancion/var_expander.c \
	  src/expancion/quotes_handler.c \
	  src/expancion/recover_value.c \
	  src/expancion/replace_var.c \
	  src/lexer/parse_user_input.c \
	  src/lexer/check_if_var.c \
	  src/lexer/token_lst_utils.c \
	  src/lexer/tokenization.c \
	  src/parser/args_echo_utils.c \
	  src/parser/args_echo.c \
	  src/parser/args.c \
	  src/parser/commands.c \
	  src/parser/heredoc_utils.c \
	  src/parser/heredoc.c \
	  src/parser/parce_word.c \
	  src/parser/parse_append.c \
	  src/parser/parse_input.c \
	  src/parser/parcer.c \
	  src/parser/test.c \
	  src/parser/trunc.c \
	  src/redirection/redirection.c \
	  src/redirection/pipes.c \
	  src/signals/signal.c \
	  src/utils/init_data.c \

OBJ = $(SRC:.c=.o)

LIBFT = ../MINISHELL/libft/libft.a

all: $(NAME)

%.o: %.c includes/bultins.h includes/parser.h includes/redirection.h includes/env.h includes/clean_and_exit.h $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re