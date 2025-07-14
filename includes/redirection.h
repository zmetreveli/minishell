/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:26:44 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/14 22:50:18 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include <stdbool.h>

//! pipes
void	close_pipe_fds(t_command *cmds, t_command *skip_cmd);
bool	create_pipes(t_data *data);
bool	set_pipe_fds(t_command *cmds, t_command *c);

//! redirections
bool	restore_io(t_io_fds *io);
bool	redirect_io(t_io_fds *io);
bool	check_infile_outfile(t_io_fds *io);

#endif
