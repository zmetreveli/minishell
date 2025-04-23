/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:34:59 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/23 12:57:47 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/env.h"
#include "../includes/bultins.h"
#include "../includes/minishell.h"
#include "../includes/execution.h"
#include "../includes/parser.h"
#include "../includes/rediction.h"
#include "../libft/libft.h"


//todo/  verifico si tengo flag -n o alguna combinacion posible valido si NO devuelvo false 

static bool	is_n_flag(char *arg)
{
	int		i;
	bool	n_flag;

	n_flag = false;
	i = 0;
	if (arg[i] != '-')
		return (n_flag);
	i++;
	while (arg[i] && arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		n_flag = true;
	return (n_flag);
}


//! Imprime los argumentos dados en STDOUT, separados por espacios.
//* Si el flag -n no está activado (n_flag == false), imprime un salto de línea al final.
//? Comienza a imprimir desde el índice i.
 
static void	echo_print_args(char **args, bool n_flag, int i)
{
	if (!args[i])
	{
		if (!n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		else if (!args[i + 1] && !n_flag)
			ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

//todo / imprimo la cadena con o sin el salto de linea dependiendo de is_N_flag 

int	echo_builtin(t_data *data, char **args)
{
	int		i;
	bool	n_flag;

	(void)data;
	n_flag = false;
	i = 1;
	while (args[i] && is_n_flag(args[i]))
	{
		n_flag = true;
		i++;
	}
	echo_print_args(args, n_flag, i);
	return (EXIT_SUCCESS);
}