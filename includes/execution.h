/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:14:12 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 23:12:26 by jbusom-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//! exec_cmd
int		execute_builtin(t_data *data, t_command *cmd);
int		execute_command(t_data *data, t_command *cmd);

//! exec_utils
bool	cmd_is_dir(char *cmd);
int		check_command_not_found(t_data *data, t_command *cmd);

//! exec
int		execute(t_data *data);

//! parse_path
char	*get_cmd_path(t_data *data, char *name);

#endif
