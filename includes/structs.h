/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:15:44 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 17:46:25 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
# include <sys/types.h>

//! Forward declaration de t_token
typedef struct s_token
{
	char			*str;
	char			*str_backup;
	bool			var_exists;
	int				type;
	int				status;
	bool			join;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

//! Primero define t_io_fds
typedef struct s_io_fds
{
	char	*infile;
	char	*outfile;
	char	*heredoc_delimiter;
	bool	heredoc_quotes;
	int		fd_in;
	int		fd_out;
	int		stdin_backup;
	int		stdout_backup;
}	t_io_fds;

//! Ahora puedes usar t_io_fds en t_command
typedef struct s_command
{
	char				*command;
	char				*path;
	char				**args;
	bool				pipe_output;
	int					*pipe_fd;
	t_io_fds			*io_fds;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

enum e_token_types
{
	SPACES = 1,
	WORD,
	VAR,
	PIPE,
	INPUT,
	TRUNC,
	HEREDOC,
	APPEND,
	END
};

//! t_data puede usar t_token y t_command sin errores
typedef struct s_data
{
	bool		interactive;
	t_token		*token;
	char		*user_input;
	char		**env;
	char		*working_dir;
	char		*old_working_dir;
	t_command	*cmd;
	pid_t		pid;
}	t_data;

enum e_quoting_status
{
	DEFAULT,
	SQUOTE,
	DQUOTE
};

#endif
