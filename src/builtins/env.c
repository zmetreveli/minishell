/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:25:11 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 17:57:20 by zmetreve         ###   ########.fr       */
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

//todo/ Has to print every env until last NULL
//todo/ To add a new ENV copy ENV and put it in 
//			own ENV and then proceed to add the next ENV var
//todo/ For shell vars, same concept, if export finds a var in shell vars, 
//			then delete that one and move it into ENV var...
int	env_builtin(t_data *data, char **args)
{
	int		i;
	char	*eq;

	if (args && args[1])
		return (errmsg_cmd("env", NULL, "Too many arguments", 2));
	i = 0;
	if (!data->env)
		return (EXIT_FAILURE);
	while (data->env[i])
	{
		eq = strchr(data->env[i], '=');
		if (eq && *(eq + 1) != '\0')
			printf("%s\n", data->env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
