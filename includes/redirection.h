/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:26:44 by zmetreve          #+#    #+#             */
/*   Updated: 2025/06/18 20:52:20 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

#include <stdbool.h>

bool	restore_io(t_io_fds *io);
bool	redirect_io(t_io_fds *io);
bool	check_infile_outfile(t_io_fds *io);


#endif