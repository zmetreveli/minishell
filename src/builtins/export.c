/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:35:20 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/10 23:45:49 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//*	Separa el argumento dado en una pareja clave-valor usando el carácter '='.
//*	Se utiliza para definir una variable de entorno.
//*	Devuelve un arreglo de 2 strings: la clave y el valor.
//*	El arreglo termina en NULL.
//*	Devuelve NULL en caso de error de asignación de memoria o entrada inválida.

static char     **get_key_value_pair(char *arg)
{
    char    **tmp;
    char    *eq_pos;

    eq_pos = ft_strchr(arg, '=');
	if (!eq_pos)
		return (NULL);
    tmp = malloc(sizeof * tmp * (2 + 1));
    tmp[0] = ft_substr(arg, 0, eq_pos - arg);
	tmp[1] = ft_substr(eq_pos, 1, ft_strlen(eq_pos));
	tmp[2] = NULL;
	return (tmp);
}

//? Agrega o actualiza variables de entorno a partir de los argumentos dados.
//? Si no se pasa ningún argumento, muestra las variables de entorno actuales.
//? Devuelve 0 si todos los argumentos son válidos, o 1 si uno o más son inválidos.

int	export_builtin(t_data *data, char **args)
{
	int		i;
	char	**tmp;
	int		ret;

	ret = EXIT_SUCCESS;
	i = 1;
	if (!args[i])
		return (env_builtin(data, NULL));
	while (args[i])
	{
		if (!is_valid_env_var_key(args[i]))
		{
			errmsg_cmd("export", args[i], "not a valid identifier", false);
			ret = EXIT_FAILURE;
		}
		else if (ft_strchr(args[i], '=') != NULL)
		{
			tmp = get_key_value_pair(args[i]);
			set_env_var(data, tmp[0], tmp[1]);
			free_str_tab(tmp);
		}
		i++;
	}
	return (ret);
}