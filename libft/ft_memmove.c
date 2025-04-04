/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:46:18 by zmetreve          #+#    #+#             */
/*   Updated: 2024/09/26 11:12:46 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	if ((size_t)dest - (size_t)src < n)
	{
		i = n - 1;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "1234567890";
    char str2[] = "1234567890";
    size_t len = 5;
    
    printf("Antes de ft_memmove (con superposición): %s\n", str1);
    ft_memmove(str1 + 3, str1, len);
    printf("Después de ft_memmove (con superposición): %s\n", str1);

    printf("\nAntes de memmove (con superposición): %s\n", str2);
    memmove(str2 + 3, str2, len);
    printf("Después de memmove (con superposición): %s\n", str2);
    
    char src[] = "Hello, world!";
    char dest_ft[50];
    char dest_orig[50];
    
    ft_memmove(dest_ft, src, strlen(src) + 1);
    memmove(dest_orig, src, strlen(src) + 1);
    printf("\nResultado de ft_memmove: %s\n", dest_ft);
    printf("Resultado de memmove: %s\n", dest_orig);

    if (strcmp(dest_ft, dest_orig) == 0)
        printf("Ambas funciones devuelven el mismo resultado.\n");
    else
        printf("Las funciones devuelven resultados diferentes.\n");

    return (0);
}*/
