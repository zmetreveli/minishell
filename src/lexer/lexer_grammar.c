/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_grammar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:40:10 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 18:02:03 by zmetreve         ###   ########.fr       */
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

static bool	consecutive_ops(t_token *token_node)
{
	if (token_node->prev)
	{
		if (token_node->type == PIPE && token_node->prev->type == PIPE)
			return (true);
		if (token_node->type > PIPE && token_node->prev->type > PIPE)
			return (true);
		if (token_node->type == END && token_node->prev->type >= PIPE)
			return (true);
	}
	return (false);
}

int	check_consecutives(t_token **token_lst)
{
	t_token	*temp;

	temp = *token_lst;
	while (temp)
	{
		if (consecutive_ops(temp) == true)
		{
			if (temp->type == END && temp->prev && temp->prev->type > PIPE)
				errmsg("syntax error near unexpected token", "newline", true);
			else if (temp->type == END && temp->prev)
				errmsg("syntax error near unexpected token",
					temp->prev->str, true);
			else
				errmsg("syntax error near unexpected token", temp->str, true);
			return (FAILURE);
		}
		temp = temp->next;
	}
	return (SUCCESS);
}
