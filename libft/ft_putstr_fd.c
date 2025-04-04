/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:21:12 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/04 06:33:10 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write (fd, s++, 1);
}
/*
int	main(void)
{
	int	fd;

	fd = open("new.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	ft_putstr_fd("hello world", fd);
	close(fd);
}*/
