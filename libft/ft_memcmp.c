/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:21:34 by zmetreve          #+#    #+#             */
/*   Updated: 2024/09/27 18:09:31 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return ((*(unsigned char *)s1 - *(unsigned char *)s2));
		s1++;
		s2++;
	}
	return (0);
}
// int main()
// {
//     char *s1 = "dda";
//     char *s2 = "aaa";
//     printf("%d\n", memcmp(s1, s2, 5));
//     printf("%d\n", ft_memcmp(s1, s2, 5));
//     return (0);
// }
