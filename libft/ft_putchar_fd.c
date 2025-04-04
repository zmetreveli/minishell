/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:20:25 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/04 06:34:56 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
#include <fcntl.h>

int	main(void)
{
	int fd;

	fd = open("open.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	ft_putchar_fd('O', fd);
	close(fd);
}*/
