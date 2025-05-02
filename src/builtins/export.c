/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:35:20 by zmetreve          #+#    #+#             */
/*   Updated: 2025/05/02 14:12:09 by jbusom-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include "../includes/env.h"
#include "../includes/bultins.h"
#include "../includes/minishell.h"
#include "../includes/execution.h"
#include "../includes/parser.h"
#include "../includes/rediction.h"
#include "../libft/libft.h"

//!	Separa el argumento dado en una pareja clave-valor usando el carácter '='.
//*	Se utiliza para definir una variable de entorno.
//*	Devuelve un arreglo de 2 strings: la clave y el valor.
//*	El arreglo termina en NULL.
//?	Devuelve NULL en caso de error de asignación de memoria o entrada inválida.

//  We need to first copy the env into a new array so we can alter it
//  Temp malloc im not sure how to do it, look into it

int	count_rows(char **src)
{
	int	i;

	while (src[i])
		i++;
	return (i);
}

char	**copy_2d_arr(char **src)
{
	char	**dest;
	int		i;
	int		rows;
	int		len;

	rows = count_rows(src);
	dest = malloc(sizeof(char *) * (rows + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		len = strlen(src[i]) + 1;
		dest[i] = malloc(sizeof(char) * len);
		if (!dest[i])
		{
			while (--i >= 0)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
		strncpy(dest[i], src[i], len);
	}
	dest[i] = NULL;
	return (dest);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void bubbleSort(char **arr, int n)
{
	int		i;
	int		j;
	int		swapped;
	char	*tmp;

	while (i < n - 1)
	{
		j = 0;
		swapped = 0;

		while (j < n - i - 1)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break;
		i++;
	}
}

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

void print_export(char **envp)
{
	int		i;
	int		size;
	char	**envp_copy;
	char	*equals;
	i = 0;
	
	envp_copy = copy_2d_arr(envp);
	size = count_rows(envp);
	bubbleSort(envp_copy, size);
    while(envp_copy[i])
	{
        equals = strchr(envp_copy[i], '=');
        if (equals)
		{
            *equals = '\0';
            printf("declare -x %s=\"%s\"\n", envp_copy[i], equals + 1);
            *equals = '=';
        }
 		i++;
    }
	free_2d_array(envp_copy);
}

//! Agrega o actualiza variables de entorno a partir de los argumentos dados.
//* Si no se pasa ningún argumento, muestra las variables de entorno actuales.
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
