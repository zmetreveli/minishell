/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:49:24 by zmetreve          #+#    #+#             */
/*   Updated: 2024/09/26 17:15:28 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "Hello, world!";
    char dest_ft[50];
    char dest_orig[50];
    size_t len = strlen(src);

    ft_memcpy(dest_ft, src, len + 1);
    memcpy(dest_orig, src, len + 1);
    printf("Resultado de ft_memcpy: %s\n", dest_ft);
    printf("Resultado de memcpy: %s\n", dest_orig);
    if (strcmp(dest_ft, dest_orig) == 0)
        printf("Ambas funciones devuelven el mismo resultado.\n");
    else
        printf("Las funciones devuelven resultados diferentes.\n");

    return 0;
}*/
