# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 01:10:05 by zmetreve          #+#    #+#              #
#    Updated: 2025/07/18 11:10:32 by zmetreve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Werror -Wextra -Wall -gdwarf-4 -g
CPPFLAGS += -I../minishell/libft

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	CFLAGS += -I/opt/homebrew/opt/readline/include
	LDFLAGS += -L/opt/homebrew/opt/readline/lib
else
	LDFLAGS +=
endif

LIBS += -lreadline

SRC = src/minishell.c \
	  src/builtins/cd.c \
	  src/builtins/echo.c \
	  src/builtins/env.c \
	  src/builtins/exit.c \
	  src/builtins/export.c \
	  src/builtins/export_utils.c \
	  src/builtins/pwd.c \
	  src/builtins/unset.c \
	  src/clean_and_exit/exit.c \
	  src/clean_and_exit/error.c \
	  src/clean_and_exit/free.c \
	  src/env/env_utils.c \
	  src/env/env.c \
	  src/executor/exec.c \
	  src/executor/exec_cmd.c \
	  src/executor/exec_utils.c \
	  src/executor/parse_path.c \
	  src/expancion/var_expander.c \
	  src/expancion/identify_var.c \
	  src/expancion/expancion_utils.c \
	  src/expancion/quotes_handler.c \
	  src/expancion/quotes_remover.c \
	  src/expancion/recover_value.c \
	  src/expancion/replace_var.c \
	  src/lexer/parse_user_input.c \
	  src/lexer/check_if_var.c \
	  src/lexer/token_lst_utils.c \
	  src/lexer/token_lst_utils_2.c \
	  src/lexer/lexer_grammar.c \
	  src/lexer/tokenization.c \
	  src/lexer/tokenization_utils.c \
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
	  src/parser/cleanup.c \
	  src/parser/pipe.c \
	  src/parser/trunc.c \
	  src/redirection/redirection.c \
	  src/redirection/pipes.c \
	  src/signals/signal.c \
	  src/utils/init_data.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ../minishell/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: make_lib $(NAME)

make_lib:
	@make -s -C $(LIBFT_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c includes/bultins.h includes/clean_and_exit.h includes/env.h includes/execution.h includes/expancion.h includes/init.h includes/lexer.h includes/minishell.h includes/parser.h includes/redirection.h includes/signals.h includes/structs.h $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
