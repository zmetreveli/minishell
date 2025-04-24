/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:24:12 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/24 19:23:05 by zmetreve         ###   ########.fr       */
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

//! Si tengo directorio guardado desde un "cd" anterior imprimo directamente
//* Si no, pido al path actual de sistema
//? Si getcwd falla muestro error

int	pwd_builtin(t_data *data, char **args)
{
	char	buf[PATH_MAX];
	char	*cwd;

	(void)args;
	if (data->working_dir)
	{
		ft_putendl_fd(data->working_dir, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	cwd = getcwd(buf, PATH_MAX);
	if (cwd)
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	errmsg_cmd("pwd", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}