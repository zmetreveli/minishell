/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:02:43 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 18:00:04 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../../includes/bultins.h"
#include "../../includes/clean_and_exit.h"
#include "../../includes/env.h"
#include "../../includes/execution.h"
#include "../../includes/expancion.h"
#include "../../includes/init.h"
#include "../../includes/lexer.h"
#include "../../includes/minishell.h"
#include "../../includes/parser.h"
#include "../../includes/redirection.h"
#include "../../includes/signals.h"
#include "../../includes/structs.h"
#include "../../libft/libft.h"

bool	cmd_is_dir(char *cmd)
{
	struct stat	cmd_stat;

	ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
	stat(cmd, &cmd_stat);
	return (S_ISDIR(cmd_stat.st_mode));
}

int	check_command_not_found(t_data *data, t_command *cmd)
{
	if (ft_strchr(cmd->command, '/') == NULL
		&& get_env_var_index(data->env, "PATH") != -1)
		return (errmsg_cmd(cmd->command, NULL, "command not found",
				CMD_NOT_FOUND));
	if (access(cmd->command, F_OK) != 0)
		return (errmsg_cmd(cmd->command, NULL, strerror(errno), CMD_NOT_FOUND));
	else if (cmd_is_dir(cmd->command))
		return (errmsg_cmd(cmd->command, NULL, "Is a directory",
				CMD_NOT_EXECUTABLE));
	else if (access(cmd->command, F_OK | X_OK) != 0)
		return (errmsg_cmd(cmd->command, NULL, strerror(errno),
				CMD_NOT_EXECUTABLE));
	return (EXIT_SUCCESS);
}
