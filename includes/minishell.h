#ifndef MINISHELL_H
# define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <termcap.h>
#include "libft.h"

typedef enum e_token_type
{
	WORD,
	STRING,
	PIPE,
	QUOTE,
	DQUOTE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC
}   t_token_type;
#endif
