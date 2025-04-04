/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:59:00 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/07 11:43:11 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	space_left;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	space_left = dstsize - dst_len - 1;
	if (space_left > 0)
	{
		if (src_len < space_left)
			ft_memcpy(dst + dst_len, src, src_len + 1);
		else
		{
			ft_memcpy(dst + dst_len, src, space_left);
			dst[dst_len + space_left] = '\0';
		}
	}
	return (dst_len + src_len);
}
/*

int main(void)
{
    char dst_ft[50] = "Hello, ";
    char dst_orig[50] = "Hello, ";
    const char *src = "world!";
    size_t dstsize = 50;
    size_t result_ft = ft_strlcat(dst_ft, src, dstsize);
    size_t result_orig = strlcat(dst_orig, src, dstsize);
    printf("Cadena destino después de ft_strlcat: %s\n", dst_ft);
    printf("Cadena destino después de strlcat: %s\n", dst_orig);
    printf("Tamaño devuelto por ft_strlcat: %zu\n", result_ft);
    printf("Tamaño devuelto por strlcat: %zu\n", result_orig)
    if (result_ft == result_orig && strcmp(dst_ft, dst_orig) == 0)
        printf("Ambas funciones devuelven el mismo resultado.\n");
    else
        printf("Las funciones devuelven resultados diferentes.\n");

    return 0;
}*/
