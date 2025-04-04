/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:21:53 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/07 09:09:34 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	*weight = 1;
	if (n < 0)
		*len += 1;
	if (n == 0)
		return ;
	while (n / *weight <= -10 || n / *weight >= 10)
	{
		*weight *= 10;
		*len += 1;
	}
}

char	*ft_itoa(int n)
{
	size_t		len;
	int			weight;
	size_t		cur;
	char		*str;

	lengths(n, &len, &weight);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	cur = 0;
	if (n < 0)
	{
		str[cur++] = '-';
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		str[cur++] = -(n / weight % 10) + '0';
		weight /= 10;
	}
	str[cur] = '\0';
	return (str);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
	int test = 1234;
	char *result = ft_itoa(test);
	printf("ft_itoa(%d) = %s\n", test, result);
	free(result);
	return (0);
}*/
