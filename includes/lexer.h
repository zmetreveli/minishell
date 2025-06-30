/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:51:14 by zmetreve          #+#    #+#             */
/*   Updated: 2025/06/30 23:33:38 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include "structs.h"

bool	parse_user_input(t_data *data);

t_token	*lst_new_token(char *str, char *str_backup, int type, int status);
void	lst_add_back_token(t_token **alst, t_token *new_node);
void	lstdelone_token(t_token *lst, void (*del)(void *));
void	lstclear_token(t_token **lst, void (*del)(void *));


int	tokenization(t_data *data, char *str);
int	check_if_var(t_token **token_lst);
int	check_consecutives(t_token **token_lst);




int	save_word_or_sep(int *i, char *str, int start, t_data *data);
int	set_status(int status, char *str, int i);
int	is_separator(char *str, int i);
int	save_word(t_token **token_lst, char *str, int index, int start);
int	save_separator(t_token **token_lst, char *str, int index, int type);
t_token	*insert_lst_between(t_token **head, t_token *to_del, t_token *insert);

#endif