/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:27:53 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 17:59:38 by zmetreve         ###   ########.fr       */
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

//! Cuenta cuántas variables de entorno originales hay.
//?	Devuelve el número de variables de entorno.

int	env_var_count(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

/*Busca una coincidencia exacta del nombre de 
	una variable en el array de entorno (env)*/
/*	La búsqueda compara la cadena "<var>="
	 con el inicio de cada entrada del entorno.*/
//?	Devuelve el índice de la coincidencia, o -1 si no se encuentra.

int	get_env_var_index(char **env, char *var)
{
	int		i;
	char	*tmp;

	tmp = ft_strjoin(var, "=");
	if (!tmp)
		return (-1);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(tmp, env[i], ft_strlen(tmp)) == 0)
		{
			free_ptr(tmp);
			return (i);
		}
		i++;
	}
	free_ptr(tmp);
	return (-1);
}

/*	Busca una coincidencia exacta del nombre de
	una variable en el array de entorno. */
/*	Si la encuentra, devuelve un puntero a 
	la parte del valor (lo que está después del '='). */
//! uso para echo $HOME
//?	Devuelve NULL si no encuentra la variable.

char	*get_env_var_value(char **env, char *var)
{
	int		i;
	char	*tmp;

	tmp = ft_strjoin(var, "=");
	if (!tmp)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(tmp, env[i], ft_strlen(tmp)) == 0)
		{
			free_ptr(tmp);
			return (ft_strchr(env[i], '=') + 1);
		}
		i++;
	}
	free_ptr(tmp);
	return (NULL);
}

//!	Verifica si key es un nombre válido para una variable de entorno.
//* es antes de anadir una variable de entorno.
/*	Devuelve true si key contiene solo
	 caracteres alfanuméricos o '_', o false si no. */

bool	is_valid_env_var_key(char *var)
{
	int	i;

	i = 0;
	if (ft_isalpha(var[i]) == 0 && var[i] != '_')
		return (false);
	i++;
	while (var[i] && var[i] != '=')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

void	init_shlvl(t_data *data)
{
	char	*shlvl_str;
	int		shlvl;
	char	*new_shlvl_str;

	shlvl_str = get_env_var_value(data->env, "SHLVL");
	if (shlvl_str)
	{
		shlvl = ft_atoi(shlvl_str);
		shlvl++;
		new_shlvl_str = ft_itoa(shlvl);
		set_env_var(data, "SHLVL", new_shlvl_str);
		free(new_shlvl_str);
	}
	else
	{
		set_env_var(data, "SHLVL", "1");
	}
}
