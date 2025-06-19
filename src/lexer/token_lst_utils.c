/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 00:08:11 by zmetreve          #+#    #+#             */
/*   Updated: 2025/06/20 00:10:04 by zmetreve         ###   ########.fr       */
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

void	lstdelone_token(t_token *lst, void (*del)(void *))
{
	if (del && lst && lst->str)
	{	
		(*del)(lst->str);
		lst->str = NULL;
	}
	if (del && lst && lst->str_backup)
	{	
		(*del)(lst->str_backup);
		lst->str_backup = NULL;
	}
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	free_ptr(lst);
}