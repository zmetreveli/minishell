/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:29:06 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/01 00:09:29 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../../includes/signals.h"
#include "../../includes/expancion.h"
#include "../../includes/clean_and_exit.h"
#include "../../includes/env.h"
#include "../../includes/structs.h"
#include "../../includes/bultins.h"
#include "../../includes/minishell.h"
#include "../../includes/execution.h"
#include "../../includes/parser.h"
#include "../../includes/redirection.h"
#include "../../libft/libft.h"

static char	*get_heredoc_name(void);
static char	*get_delim(char *delim, bool *quotes);

bool	get_heredoc(t_data *data, t_io_fds *io)
{
	int		tmp_fd;
	bool	ret;
	
	ret = true;
	tmp_fd = open(io->infile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ret = fill_heredoc(data, io, tmp_fd);
	close(tmp_fd);
	return (ret);
}

//! nombre de heredoc

static char	*get_heredoc_name(void)
{
	static int	i;
	char		*name;
	char		*number;
	
	number = ft_itoa(i);
	if (!number)
	return (NULL);
	name = ft_strjoin(HEREDOC_NAME, number);
	free(number);
	i++;
	return (name);
}



//* delimitador

static char	*get_delim(char *delim, bool *quotes)
{
	int	len;
	
	len = ft_strlen(delim) - 1;
	if ((delim[0] == '\"' && delim[len] == '\"')
	|| (delim[0] == '\'' && delim[len] == '\''))
	{
		*quotes = true;
		return (ft_strtrim(delim, "\'\""));
	}
	return (ft_strdup(delim));
}

//! creamos heredoc temporal para user input

void	parse_heredoc(t_data *data, t_command **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_command	*cmd;
	t_io_fds	*io;
	
	temp = *token_lst;
	cmd = lst_last_cmd(*last_cmd);
	init_io(cmd);
	io = cmd->io_fds;
	if (!remove_old_file_ref(io, true))
	return ;
	io->infile = get_heredoc_name();
	io->heredoc_delimiter = get_delim(temp->next->str, &(io->heredoc_quotes));
	if (get_heredoc(data, io))
	io->fd_in = open(io->infile, O_RDONLY);
	else
	io->fd_in = -1;
	if (temp->next->next)
	temp = temp->next->next;
	else
	temp = temp->next;
	*token_lst = temp;
}