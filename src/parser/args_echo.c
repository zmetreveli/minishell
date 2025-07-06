/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:14:05 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/05 23:51:01 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../../includes/clean_and_exit.h"
#include "../../includes/env.h"
#include "../../includes/structs.h"
#include "../../includes/bultins.h"
#include "../../includes/minishell.h"
#include "../../includes/execution.h"
#include "../../includes/parser.h"
#include "../../includes/redirection.h"
#include "../../libft/libft.h"

//! Esta función gestiona el caso específico cuando el comando es "echo":
//*  Reserva memoria para el array de argumentos usando la función count_args.
//   Recorre la lista de tokens mientras sean de tipo VAR o WORD:
/*  Si el token tiene "join = true", junta todos los
	 tokens consecutivos de tipo VAR con join = true. */
//? Si "join = false", simplemente duplica el string del token en args[i].

int	create_args_echo_mode(t_token **token_node, t_command *last_cmd)
{
	int		nb_args;
	t_token	*temp;
	int		i;

	remove_empty_var_args(token_node);
	temp = *token_node;
	nb_args = count_args(temp);
	last_cmd->args = malloc(sizeof(char *) * (nb_args + 2));
	if (!last_cmd->args)
		return (FAILURE);
	i = 0;
	last_cmd->args[i] = ft_strdup(last_cmd->command);
	i++;
	while (temp->type == WORD || temp->type == VAR)
	{
		if (temp->join == true)
			last_cmd->args[i] = join_vars(&temp);
		else
			last_cmd->args[i] = ft_strdup(temp->str);
		i++;
		temp = temp->next;
	}
	last_cmd->args[i] = NULL;
	*token_node = temp;
	return (SUCCESS);
}

int	add_args_echo_mode(t_token **token_node, t_command *last_cmd)
{
	int		len;
	int		nb_args;
	char	**new_tab;
	t_token	*temp;

	remove_empty_var_args(token_node);
	temp = *token_node;
	nb_args = count_args(temp);
	len = 0;
	while (last_cmd->args[len])
		len++;
	new_tab = malloc(sizeof(char *) * (nb_args + len + 1));
	if (!new_tab)
		return (FAILURE);
	new_tab = copy_in_new_tab(len, new_tab, last_cmd, temp);
	free(last_cmd->args);
	last_cmd->args = new_tab;
	while (temp->type == WORD || temp->type == VAR)
		temp = temp->next;
	*token_node = temp;
	return (SUCCESS);
}
