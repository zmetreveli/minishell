/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:14:12 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/18 20:20:51 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//! env.c
int			env_var_count(char **env);
int			get_env_var_index(char **env, char *var);
char		*get_env_var_value(char **env, char *var);
bool		is_valid_env_var_key(char *var);

//! env_utils.c
bool		set_env_var(t_data *data, char *key, char *value);
bool		remove_env_var(t_data *data, int idx);

//! builtins
int			env_builtin(t_data *data, char **args);
int			pwd_builtin(t_data *data, char **args);
int			echo_builtin(t_data *data, char **args);
int			export_builtin(t_data *data, char **args);
int			unset_builtin(t_data *data, char **args);
int			cd_builtin(t_data *data, char **args);
int			exit_builtin(t_data *data, char **args);

#endif