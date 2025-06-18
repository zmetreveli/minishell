/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:57:21 by zmetreve          #+#    #+#             */
/*   Updated: 2025/06/18 19:37:25 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include <stdbool.h>
#include "structs.h"

//! env_utils

bool	set_env_var(t_data *data, char *key, char *value);
bool	remove_env_var(t_data *data, int idx);

//! env

bool	is_valid_env_var_key(char *var);
char	*get_env_var_value(char **env, char *var);
int	get_env_var_index(char **env, char *var);
int env_var_count(char **env);

#endif