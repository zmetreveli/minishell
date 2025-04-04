/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:08:52 by zmetreve          #+#    #+#             */
/*   Updated: 2024/09/28 11:30:23 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (unsigned char)c))
		s++;
	if (*s == (unsigned char)c)
	{
		return ((char *)s);
	}
	return ((char *)0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str[] = "Hello, world!";
    int ch = 'o';
    char *result_ft = ft_strchr(str, ch);
    char *result_orig = strchr(str, ch);
    printf("Cadena original: %s\n", str);
    printf("Resultado de ft_strchr: %s\n", result_ft ? result_ft : "NULL");
    printf("Resultado de strchr: %s\n", result_orig ? result_orig : "NULL");
    if (result_ft == result_orig)
        printf("Ambas funciones devuelven el mismo resultado.\n");
    else
        printf("Las funciones devuelven resultados diferentes.\n");

    return 0;
}*/
