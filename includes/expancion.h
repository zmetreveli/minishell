/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expancion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:01:51 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 23:15:06 by jbusom-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANCION_H
# define EXPANCION_H

# include "structs.h"

//! expancion_utils
void	copy_var_value(char *new_str, char *var_value, int *j);
char	*get_new_token_string(char *oldstr, char *var_value,
			int newstr_size, int index);

//! identify_var
bool	is_var_compliant(char c);
int		var_length(char *str);
char	*identify_var(char *str);

//! quotes_handler
int		count_len(char *str, int count, int i);
bool	quotes_in_string(char *str);
int		handle_quotes(t_data *data);

//! quotes_remover
int		remove_quotes(t_token **token_node);

//! recover_value
char	*recover_val(t_token *token, char *str, t_data *data);

//! replace_var
int		replace_var(t_token **token_node, char *var_value, int index);
char	*replace_str_heredoc(char *str, char *var_value, int index);

//! var_expander
int		var_expander(t_data *data, t_token **token_lst);
char	*var_expander_heredoc(t_data *data, char *str);

#endif
