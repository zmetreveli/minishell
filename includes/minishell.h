/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:26:30 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 23:16:49 by jbusom-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <stdbool.h>

//! inc internos
# include "../includes/init.h"
# include "../includes/structs.h"
# include "../includes/env.h"
# include "../includes/bultins.h"
# include "../includes/execution.h"
# include "../includes/parser.h"
# include "../libft/libft.h"

# define HEREDOC_NAME "/tmp/.minishell_heredoc_"

# define CMD_NOT_FOUND 127
# define CMD_NOT_EXECUTABLE 126

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

# define SUCCESS 0
# define FAILURE 1

extern int	g_last_exit_code;

void	get_time_prompt(char *buffer, size_t size, t_data *data);
void	minishell_noninteractive(t_data *data, char *arg);
void	minishell_interactive(t_data *data);
int		main(int ac, char **av, char **env);

#endif
