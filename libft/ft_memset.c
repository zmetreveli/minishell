/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:23:55 by zmetreve          #+#    #+#             */
/*   Updated: 2024/09/24 18:51:12 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str_ft[50] = "Hello, world!";
    char str_orig[50] = "Hello, world!";
    int ch = '*';
    size_t len = 5;

    printf("Antes de ft_memset: %s\n", str_ft);
    ft_memset(str_ft, ch, len);
    printf("Después de ft_memset: %s\n", str_ft);
    printf("\nAntes de memset: %s\n", str_orig);
    memset(str_orig, ch, len);
    printf("Después de memset: %s\n", str_orig);
    if (strncmp(str_ft, str_orig, len) == 0)
        printf("\nAmbas funciones devuelven el mismo 
        resultado en los primeros %zu caracteres.\n", len);
    else
        printf("\nLas funciones devuelven resultados diferentes.\n");

    return (0);
}*/
