/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:16:15 by zmetreve          #+#    #+#             */
/*   Updated: 2024/09/27 15:15:00 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s) + 1;
	while (i--)
	{
		if (*(s + i) == (unsigned char)c)
			return ((char *)(s + i));
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *s, int c);

int main() {
    const char *test_string = "Hello, world! Hello again!";
    int test_char;
    char *result_ft;
    char *result_orig;

    test_char = 'o';
    result_ft = ft_strrchr(test_string, test_char);
    result_orig = strrchr(test_string, test_char);
    printf("ft_strrchr: %s\n", result_ft);
    printf("strrchr: %s\n", result_orig);

    return (0);
}*/
