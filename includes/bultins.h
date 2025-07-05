/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultins.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:58:56 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/06 01:12:16 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTINS_H
# define BULTINS_H

//! cd_builtin
int	cd_builtin(t_data *data, char **args);

//! echo_builtin
int	echo_builtin(t_data *data, char **args);

//! env_builtin
int	env_builtin(t_data *data, char **args);

//! exit_builtin
int	exit_builtin(t_data *data, char **args);

//! export_builtin
int	export_builtin(t_data *data, char **args);

//! pwd_builtin
int	pwd_builtin(t_data *data, char **args);

//! unset_builtin
int	unset_builtin(t_data *data, char **args);

#endif
