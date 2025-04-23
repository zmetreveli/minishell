/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:34:31 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/23 12:57:37 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/env.h"
#include "../includes/bultins.h"
#include "../includes/minishell.h"
#include "../includes/execution.h"
#include "../includes/parser.h"
#include "../includes/rediction.h"
#include "../libft/libft.h"


//! Actualiza las variables PWD y OLDPWD en el entorno después de un cambio de directorio.
//* Se guarda una copia de las rutas internamente para usarlas en caso de que
//? las variables de entorno hayan sido eliminadas.

static void	update_wds(t_data *data, char *wd)
{
	set_env_var(data, "OLDPWD", get_env_var_value(data->env, "PWD"));
	set_env_var(data, "PWD", wd);
	if (data->old_working_dir)
	{
		free_ptr(data->old_working_dir);
		data->old_working_dir = ft_strdup(data->working_dir);
	}
	if (data->working_dir)
	{
		free_ptr(data->working_dir);
		data->working_dir = ft_strdup(wd);
	}
	free_ptr(wd);
}

//todo / si falla la ruta o se borra devolvemos mensaje msads claro "como en bash"

static bool chdir_errno_mod(char *path)
{
	if (errno == ESTALE)
		errno = ENOENT;
	errmsg_cmd("cd", path, strerror(errno), errno);
	return (false);
}

//todo / cambio directoryo y acualiso pwd con la nueva direccion

static bool change_dir(t_data *data, char *path)
{
	char	*tmp;
	char	*ret;
	char	*cwd[PATH_MAX];

	ret = NULL;
	if (chdir(path) != 0)
		return (chdir_errno_mod(path));
	ret = getcwd(cwd, PATH_MAX);
	if (!ret)
	{
		errmsg_cmd("cd: error retriving current directory", 
			"getcwd: cannot access parent directories",
			strerror(errno), errno);
		ret = ft_strjoin(data->working_dir, "/");
		tmp = ret;
		ret = ft_strjoin(tmp, path);
		free_ptr(tmp);
	}
	else
		ret = ft_strdup(cwd);
	update_wds(data, ret);
	return (true);
}

//todo / cambio directorio con cd O voy al HOME si es solo cd sin la ruta

int	cd_builtin(t_data *data, char **args)
{
	char	*path;

	if (!args || !args[1] || ft_isspace(args[1][0])
		|| args[1][0] == '\0' || ft_strncmp(args[1], "--", 3) == 0)
	{
		path = get_env_var_value(data->env, "HOME");
		if (!path || *path == '\0' || ft_isspace(*path))
			return (errmsg_cmd("cd", NULL, "HOME not set", EXIT_FAILURE));
		return (!change_dir(data, path));
	}
	if (args[2])
		return (errmsg_cmd("cd", NULL, "too many arguments", EXIT_FAILURE));
	if (ft_strncmp(args[1], "-", 2) == 0)
	{
		path = get_env_var_value(data->env, "OLDPWD");
		if (!path)
			return (errmsg_cmd("cd", NULL, "OLDPWD not set", EXIT_FAILURE));
		return (!change_dir(data, path));
	}
	return (!change_dir(data, args[1]));
}