/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:57:38 by zmetreve          #+#    #+#             */
/*   Updated: 2024/09/30 17:46:40 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
int main() 
{
    size_t count = 5;
    size_t size = sizeof(int);

    int *original = (int *)calloc(count, size);
    if (!original)
    {
        printf("calloc error\n");
        return (1);
    }


    int *custom = (int *)ft_calloc(count, size);
    if (!custom)
    {
        printf("ft_calloc error\n");
        return (1);
    }

    int identical = 1;
    for (size_t i = 0; i < count; i++)
    {
        if (original[i] != custom[i])
        {
            identical = 0;
            break;
        }
    }

    if (identical)
    {
        printf("ft_calloc es identico calloc-ს!\n");
    }
    else 
    {
        printf("ft_calloc es identico calloc-ს.\n");
    }

    free(original);
    free(custom);

    return 0;
}*/
