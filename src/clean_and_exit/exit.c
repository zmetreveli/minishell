/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:12:33 by zmetreve          #+#    #+#             */
/*   Updated: 2025/06/18 22:52:34 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/clean_and_exit.h"
#include "../includes/structs.h"
#include "../includes/env.h"
#include "../includes/bultins.h"
#include "../includes/minishell.h"
#include "../includes/execution.h"
#include "../includes/parser.h"
#include "../includes/rediction.h"
#include "../libft/libft.h"


void	exit_shell(t_data *data, int exno)
{
	if (data)
	{
		if (data->cmd && data->cmd->io_fds)
			close_fds(data->cmd, true);
		free_data(data, true);
	}
	exit(exno);
}