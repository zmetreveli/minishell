/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:16:28 by zmetreve          #+#    #+#             */
/*   Updated: 2024/09/28 11:32:27 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
/*
int main(void)
{
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, everyone!";
    size_t n = 7;
    int result_ft = ft_strncmp(str1, str2, n);
    int result_orig = strncmp(str1, str2, n);
    printf("Resultado de ft_strncmp: %d\n", result_ft);
    printf("Resultado de strncmp: %d\n", result_orig);
    if (result_ft == result_orig)
        printf("Ambas funciones devuelven el mismo resultado.\n");
    else
        printf("Las funciones devuelven resultados diferentes.\n");

    return 0;
}*/
