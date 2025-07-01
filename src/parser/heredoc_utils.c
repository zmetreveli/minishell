/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:38:05 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/01 01:58:53 by zmetreve         ###   ########.fr       */
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

static bool evaluate_heredoc_line(t_data *data, char **line, t_io_fds *io, bool *ret);
static char *get_expanded_var_line(t_data *data, char *line);
static char *make_str_from_tab(char **tab);



static char	*make_str_from_tab(char **tab)
{
	char	*str;
	char	*tmp;
	int		i;
	
	i = -1;
	while (tab[++i])
	{
		tmp = str;
		if (i == 0)
		str = ft_strdup(tab[0]);
		else
		{
			str = ft_strjoin(tmp, tab[i]);
			free_ptr(tmp);
		}
		if (tab[i + 1])
		{
			tmp = str;
			str = ft_strjoin(tmp, " ");
			free_ptr(tmp);
		}
	}
	free_str_tab(tab);
	return (str);
}

static char	*get_expanded_var_line(t_data *data, char *line)
{
	char	**words;
	int		i;
	
	words = ft_split(line, ' ');
	if (!words)
	return (NULL);
	i = 0;
	while (words[i])
	{
		if (ft_strchr(words[i], '$'))
		{
			words[i] = var_expander_heredoc(data, words[i]);
			if (!words[i])
			return (NULL);
		}
		i++;
	}
	return (make_str_from_tab(words));
}


static bool	evaluate_heredoc_line(t_data *data, char **line,
	t_io_fds *io, bool *ret)
	{
		if (*line == NULL)
		{
			errmsg_cmd("warning", "here-document delimited by end-of-file: wanted",
				io->heredoc_delimiter, true);
				*ret = true;
				return (false);
			}
	if (ft_strcmp(*line, io->heredoc_delimiter) == 0)
	{
		*ret = true;
		return (false);
	}
	if (io->heredoc_quotes == false && ft_strchr(*line, '$'))
	{
		*line = get_expanded_var_line(data, *line);
		if (!(*line))
		{
			free_ptr(*line);
			*ret = false;
			return (false);
		}
	}
	return (true);
}

bool	fill_heredoc(t_data *data, t_io_fds *io, int fd)
{
	char	*line;
	bool	ret;
	
	ret = false;
	line = NULL;
	while (1)
	{
		set_signals_interactive();
		line = readline(">");
		set_signals_noninteractive();
		if (!evaluate_heredoc_line(data, &line, io, &ret))
		break ;
		ft_putendl_fd(line, fd);
		free_ptr(line);
	}
	free_ptr(line);
	return (ret);
}