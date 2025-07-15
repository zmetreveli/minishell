/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:42:31 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 17:47:54 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../../includes/clean_and_exit.h"
#include "../../includes/lexer.h"
#include "../../includes/env.h"
#include "../../includes/structs.h"
#include "../../includes/bultins.h"
#include "../../includes/minishell.h"
#include "../../includes/execution.h"
#include "../../includes/parser.h"
#include "../../includes/redirection.h"
#include "../../libft/libft.h"

void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free_ptr(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_data(t_data *data, bool clear_history)
{
	if (data && data->user_input)
	{
		free_ptr(data->user_input);
		data->user_input = NULL;
	}
	if (data && data->token)
		lstclear_token(&data->token, &free_ptr);
	if (data && data->cmd)
		lst_clear_cmd(&data->cmd, &free_ptr);
	if (clear_history == true)
	{
		if (data && data->working_dir)
			free_ptr(data->working_dir);
		if (data && data->old_working_dir)
			free_ptr(data->old_working_dir);
		if (data && data->env)
			free_str_tab(data->env);
		rl_clear_history();
	}
}

void	free_io(t_io_fds *io)
{
	if (!io)
		return ;
	restore_io(io);
	if (io->heredoc_delimiter)
	{
		unlink(io->infile);
		free_ptr(io->heredoc_delimiter);
	}
	if (io->infile)
		free_ptr(io->infile);
	if (io->outfile)
		free_ptr(io->outfile);
	if (io)
		free_ptr(io);
}

void	close_fds(t_command *cmds, bool close_backups)
{
	if (cmds->io_fds)
	{
		if (cmds->io_fds->fd_in != -1)
			close(cmds->io_fds->fd_in);
		if (cmds->io_fds->fd_out != -1)
			close(cmds->io_fds->fd_out);
		if (close_backups)
			restore_io(cmds->io_fds);
	}
	close_pipe_fds(cmds, NULL);
}

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
