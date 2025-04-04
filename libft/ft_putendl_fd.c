/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 06:36:53 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/04 07:12:17 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	nl;

	nl = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &nl, 1);
}
/*
int	main(void)
{
	int	fd;

	fd = open("morning.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	ft_putendl_fd("good morning", fd);
	close(fd);
}*/
