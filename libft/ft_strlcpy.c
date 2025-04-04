/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:25:02 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/04 11:29:25 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		if (src_len < size - 1)
		{
			ft_memcpy(dst, src, src_len + 1);
		}
		else
		{
			ft_memcpy(dst, src, size - 1);
			dst[size - 1] = '\0';
		}
	}
	return (src_len);
}
/*
int main(void)
{
    char src[] = "Hello, world!";
    char dst_ft[50];
    char dst_orig[50];
    size_t size = 10;
    size_t result_ft = ft_strlcpy(dst_ft, src, size);
    size_t result_orig = strlcpy(dst_orig, src, size);
    printf("Cadena destino después de ft_strlcpy: %s\n", dst_ft);
    printf("Cadena destino después de strlcpy: %s\n", dst_orig);
    printf("Tamaño devuelto por ft_strlcpy: %zu\n", result_ft);
    printf("Tamaño devuelto por strlcpy: %zu\n", result_orig);
    if (result_ft == result_orig && strcmp(dst_ft, dst_orig) == 0)
        printf("Ambas funciones devuelven el mismo resultado.\n");
    else
        printf("Las funciones devuelven resultados diferentes.\n");

    return 0;
}*/
