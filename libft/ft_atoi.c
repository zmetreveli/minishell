/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:37:29 by zmetreve          #+#    #+#             */
/*   Updated: 2024/09/30 14:55:46 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	res = 0;
	while (ft_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * s);
}

/*#include <stdio.h>
int main()
{
    const char *str1 = "12345";
    const char *str2 = "   -42";
    const char *str3 = "+987";
    const char *str4 = "123abc456";
    const char *str5 = "hello";
    const char *str6 = "";

    printf("atoi('%s') = %d | ft_atoi('%s') = %d\n",
	str1, atoi(str1), str1, ft_atoi(str1));
    printf("atoi('%s') = %d | ft_atoi('%s') = %d\n", 
	str2, atoi(str2), str2, ft_atoi(str2));
    printf("atoi('%s') = %d | ft_atoi('%s') = %d\n",
	str3, atoi(str3), str3, ft_atoi(str3));
    printf("atoi('%s') = %d | ft_atoi('%s') = %d\n",
	str4, atoi(str4), str4, ft_atoi(str4));
    printf("atoi('%s') = %d | ft_atoi('%s') = %d\n",
	str5, atoi(str5), str5, ft_atoi(str5));
    printf("atoi('%s') = %d | ft_atoi('%s') = %d\n",
	str6, atoi(str6), str6, ft_atoi(str6));

    return (0);
}*/
