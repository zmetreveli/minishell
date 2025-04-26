/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:19:23 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/26 23:01:13 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_AND_EXIT_H
# define CLEAN_AND_EXIT_H

# include <stdbool.h>

typedef struct s_data t_data;

//! exit.c

void    exit_shell(t_data *data, int exno);

//! free.c

void	free_str_tab(char **tab);
void	free_data(t_data *data, bool clear_history);

//! error.c

bool	usage_message(bool return_val);

#endif
