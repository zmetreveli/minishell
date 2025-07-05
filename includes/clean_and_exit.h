/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:19:23 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/06 01:15:55 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_AND_EXIT_H
# define CLEAN_AND_EXIT_H

# include <stdbool.h>
# include "structs.h" 

typedef struct s_data	t_data;

//! exit.c

void	exit_shell(t_data *data, int exno);

//! free.c

void	free_str_tab(char **tab);
void	free_data(t_data *data, bool clear_history);
void	free_io(t_io_fds *io);
void	free_ptr(void *ptr);
void	close_fds(t_command *cmds, bool close_backups);

//! error.c

bool	usage_message(bool return_val);
int		errmsg_cmd(char *command, char *detail,
			char *error_message, int error_nb);
void	errmsg(char *errmsg, char *detail, int quotes);
char	*join_strs(char *str, char *add);

#endif
