/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:14:59 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/07 09:41:27 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[] = "Hello, world!";
    int ch = 'o';
    size_t len = strlen(str);
    char *result_ft = ft_memchr(str, ch, len);
    char *result_orig = memchr(str, ch, len);
    printf("Resultado de ft_memchr: %s\n", result_ft ? result_ft : "NULL");
    printf("Resultado de memchr: %s\n", result_orig ? result_orig : "NULL");
    if (result_ft == result_orig)
        printf("Ambas funciones devuelven el mismo resultado.\n");
    else
        printf("Las funciones devuelven resultados diferentes.\n");

    return 0;
}*/
