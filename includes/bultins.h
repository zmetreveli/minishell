/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:58:56 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 23:11:41 by jbusom-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BULTINS_H

# include "structs.h"

//! cd
int		cd_builtin(t_data *data, char **args);

//! echo
int		echo_builtin(t_data *data, char **args);

//! env
int		env_builtin(t_data *data, char **args);

//! exit
int		exit_builtin(t_data *data, char **args);

//! export
int		export_builtin(t_data *data, char **args);
int		count_rows(char **src);
char	**copy_2d_arr(char **src);
void	free_2d_array(char **arr);
void	bubbleSort(char **arr, int n);
void	print_export(char **envp);
void	handle_export_arg(t_data *data, char *arg, int *ret);

//! pwd
int		pwd_builtin(t_data *data, char **args);

//! unset
int		unset_builtin(t_data *data, char **args);

#endif
