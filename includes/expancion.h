/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expancion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:01:51 by zmetreve          #+#    #+#             */
/*   Updated: 2025/06/28 19:13:41 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
#define EXPANSION_H

# include "structs.h"

int	var_expander(t_data *data, t_token **token_lst);
char	*var_expander_heredoc(t_data *data, char *str);
int	handle_quotes(t_data *data);
int	replace_var(t_token **token_node, char *var_value, int index);
char	*replace_str_heredoc(char *str, char *var_value, int index);
char	*recover_val(t_token *token, char *str, t_data *data);

int	count_len(char *str, int count, int i);
bool	quotes_in_string(char *str);
int	remove_quotes(t_token **token_node);

#endif