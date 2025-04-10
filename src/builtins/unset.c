/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:25:42 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/11 00:22:23 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// *	Procesa cada argumento como un posible nombre de variable de entorno.
// *	Si el nombre es válido y existe en el entorno, se elimina.
// *	Los identificadores inválidos o que contienen '=' generan un mensaje de error.
// ?	Devuelve 0 si todas las variables fueron eliminadas correctamente,
// *	o 1 si ocurrió algún error.


int	unset_builtin(t_data *data, char **args)
{
	int	i;
	int	idx;
	int	ret;

	ret = EXIT_SUCCESS;
	i = 1;
	while (args[i])
	{
		if (!is_valid_env_var_key(args[i]) || ft_strchr(args[i], '=') != NULL)
		{
			errmsg_cmd("unset", args[i], "not a valid identifier", false);
			ret = EXIT_FAILURE;
		}
		else
		{
			idx = get_env_var_index(data->env, args[i]);
			if (idx != -1)
				remove_env_var(data, idx);
		}
		i++;
	}
	return (ret);
}