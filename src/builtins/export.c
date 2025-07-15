/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:35:20 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 17:57:52 by zmetreve         ###   ########.fr       */
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

//!	Separa el argumento dado en una pareja clave-valor usando el carácter '='.
//*	Se utiliza para definir una variable de entorno.
//*	Devuelve un arreglo de 2 strings: la clave y el valor.
//*	El arreglo termina en NULL.
//?	Devuelve NULL en caso de error de asignación de memoria o entrada inválida.

static char	**get_key_value_pair(char *arg)
{
	char	**tmp;
	char	*eq_pos;

	eq_pos = ft_strchr(arg, '=');
	if (!eq_pos)
		return (NULL);
	tmp = malloc(sizeof * tmp * (2 + 1));
	tmp[0] = ft_substr(arg, 0, eq_pos - arg);
	tmp[1] = ft_substr(eq_pos, 1, ft_strlen(eq_pos));
	tmp[2] = NULL;
	return (tmp);
}

//! Agrega o actualiza variables de entorno a partir de los argumentos dados.
//* Si no se pasa ningún argumento, muestra las variables de entorno actuales.

void	handle_export_arg(t_data *data, char *arg, int *ret)
{
	char	**tmp;

	if (!is_valid_env_var_key(arg))
	{
		errmsg_cmd("export", arg, "not a valid identifier", false);
		*ret = EXIT_FAILURE;
	}
	else if (ft_strchr(arg, '=') != NULL)
	{
		tmp = get_key_value_pair(arg);
		set_env_var(data, tmp[0], tmp[1]);
		free_str_tab(tmp);
	}
	else
		set_env_var(data, arg, "");
}

int	export_builtin(t_data *data, char **args)
{
	int		i;
	int		ret;

	ret = EXIT_SUCCESS;
	i = 1;
	if (!args[i])
	{
		print_export(data->env);
		return (ret);
	}
	while (args[i])
	{
		handle_export_arg(data, args[i], &ret);
		i++;
	}
	return (ret);
}
