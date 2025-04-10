/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:27:53 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/10 11:34:01 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Cuenta cuántas variables de entorno originales hay.
//	Devuelve el número de variables de entorno.

int env_var_count(char *env)
{
    int i;

    i = 0;
    while (env && env[i])
        i++;
    return (i);
}

