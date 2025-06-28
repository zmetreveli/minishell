/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:26:30 by zmetreve          #+#    #+#             */
/*   Updated: 2025/06/28 22:59:26 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SUCCESS 0
# define FAILURE 1

#include <stdio.h>
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
# include <stdbool.h>

//! inc internos
#include "../includes/init.h"
#include "../includes/structs.h"
#include "../includes/env.h"
#include "../includes/bultins.h"
// !#include "../includes/minishell.h"
#include "../includes/execution.h"
#include "../includes/parser.h"
//#include "../includes/rediction.h"
#include "../libft/libft.h"

#define HEREDOC_NAME "/tmp/.heredoc_"

# define CMD_NOT_FOUND 127
# define CMD_NOT_EXECUTABLE 126

extern int	g_last_exit_code;

# define PROMPT "\001\e[45m\002>>> \001\e[0m\e[33m\002 Minishell>$ \001\e[0m\002"

#endif
