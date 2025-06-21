/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expancion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 20:01:51 by zmetreve          #+#    #+#             */
/*   Updated: 2025/06/22 00:19:56 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
#define EXPANSION_H

# include "structs.h"

int	var_expander(t_data *data, t_token **token_lst);
char	*var_expander_heredoc(t_data *data, char *str);

#endif