/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 07:13:26 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/04 07:31:06 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	b;

	b = n;
	if (b < 0)
	{
		ft_putchar_fd('-', fd);
		b = b * -1;
	}
	if (b > 9)
	{
		ft_putnbr_fd(b / 10, fd);
		ft_putnbr_fd(b % 10, fd);
	}
	else
		ft_putchar_fd(b + '0', fd);
}
/*
int main ()
{
	int num0 = -2147483648;
	int num1 = 2147483647;
	int num2 = 42;

	ft_putnbr_fd(num0, 1);
	printf("\n");

	ft_putnbr_fd(num1, 1);
	printf("\n");

	ft_putnbr_fd(num2, 1);
	printf("\n");

	return (0);
}*/
