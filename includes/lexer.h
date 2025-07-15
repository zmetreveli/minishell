/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:51:14 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 23:13:07 by jbusom-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "structs.h"

//! check_if_var
int		check_if_var(t_token **token_lst);

//! lexer_grammar
int		check_consecutives(t_token **token_lst);

//! parse_user_input
bool	parse_user_input(t_data *data);

//! token_lst_utils_2
t_token	*insert_lst_between(t_token **head, t_token *to_del, t_token *insert);

//! token_lst_utils
t_token	*lst_new_token(char *str, char *str_backup, int type, int status);
void	lst_add_back_token(t_token **alst, t_token *new_node);
void	lstdelone_token(t_token *lst, void (*del)(void *));
void	lstclear_token(t_token **lst, void (*del)(void *));

//! tokenization_utils
int		save_separator(t_token **token_lst, char *str, int index, int type);
int		save_word(t_token **token_lst, char *str, int index, int start);
int		is_separator(char *str, int i);
int		set_status(int status, char *str, int i);
int		save_word_or_sep(int *i, char *str, int start, t_data *data);

//! tokenization
int		tokenization(t_data *data, char *str);

#endif
