/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:31:55 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 17:59:29 by zmetreve         ###   ########.fr       */
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

//! Realoca memoria para la variable global g_env_vars.
//?	Devuelve un puntero a las nuevas variables de entorno
//  o NULL en caso de error de asignación de memoria.

static char	**realloc_env_vars(t_data *data, int size)
{
	char	**new_env;
	int		i;

	new_env = ft_calloc(size + 1, sizeof * new_env);
	if (!new_env)
		return (NULL);
	i = 0;
	while (data->env[i] && i < size)
	{
		new_env[i] = ft_strdup(data->env[i]);
		free_ptr(data->env[i]);
		i++;
	}
	free(data->env);
	return (new_env);
}

/*	Agrega una variable de entorno con la clave dada correspondiente
    al valor dado. Si la clave ya existe en las variables de entorno, 
	el valor será sobrescrito. Si no, se crea una nueva entrada. */
//?	Devuelve 1 si la operación fue exitosa, o 0 en caso de error.

bool	set_env_var(t_data *data, char *key, char *value)
{
	int		idx;
	char	*tmp;

	idx = get_env_var_index(data->env, key);
	if (value == NULL)
		value = "";
	tmp = ft_strjoin("=", value);
	if (!tmp)
		return (false);
	if (idx != -1 && data->env[idx])
	{
		free_ptr(data->env[idx]);
		data->env[idx] = ft_strjoin(key, tmp);
	}
	else
	{
		idx = env_var_count(data->env);
		data->env = realloc_env_vars(data, idx + 1);
		if (!data->env)
			return (false);
		data->env[idx] = ft_strjoin(key, tmp);
	}
	free_ptr(tmp);
	return (true);
}

/* Elimina la variable de entorno en la posición indicada del array
   env Desplaza el resto de las variables una posición
    hacia atrás y realoca memoria. */
/*	Devuelve true si tuvo éxito, o false si el índice
   es inválido o falla la reasignación de memoria. */

bool	remove_env_var(t_data *data, int idx)
{
	int	i;
	int	count;

	if (idx > env_var_count(data->env))
		return (false);
	free_ptr(data->env[idx]);
	i = idx;
	count = idx;
	while (data->env[i + 1])
	{
		data->env[i] = ft_strdup(data->env[i + 1]);
		free_ptr(data->env[i + 1]);
		count++;
		i++;
	}
	data->env = realloc_env_vars(data, count);
	if (!data->env)
		return (false);
	return (true);
}
