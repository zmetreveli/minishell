/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:26:12 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/16 11:39:13 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Todo/  controlamos si el numero esta dentro del rango

static bool    chek_out_of_range(int neg, unsigned long long num, bool *error)
{
    if ((neg == 1 && num > LONG_MAX)
        || (neg == -1 && num > -(unsigned long)LONG_MIN))
        *error = true;
    return (*error);
}

static int ft_atoi_long(const char *str, bool *error)
{
    unsigned long long  num;
    int neg;
    int i;

    num = 0;
    neg = 1;
    i = 0;
    while (str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        neg *= -1;
        i++;
    }
    while (str[i] && ft_isdigit(str[i]))
    {
        num = (num * 10) + (str[i] - '0');
        if (check_out_of_range(neg, num, error))
            break ;
        i++;
    }
    return (num * neg);
}


//!	Analiza el argumento dado como un código de salida.
//*	Verifica si hay caracteres inválidos, signos incorrectos o desbordamiento.
//	Si la entrada no es válida (no numérica, vacía o fuera de rango),
//?	establece el flag de error en true.
//todo	Devuelve el código de salida módulo 256 (como hacen las shells).
//? Si el argumento es NULL, devuelve el último código de salida.

static int get_exit_code(char *arg, bool *error)
{
    unsigned long long i;

    if (!arg)
        return (g_last_exit_code);
    i = 0;
    while (ft_isspace(arg[i]))
        i++;
    if (arg[i] == '\0')
        *error = true;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    if (!ft_isdigit(arg[i]))
        *error = true;
    while (arg[i])
    {
        if (!ft_isdigit(arg[i]) && !ft_isspace(arg[i]))
            *error = ture;
        i++;
    }
    i = ft_atoi_long(arg, error);
    return (i % 256);
}

//!	Verifica si el comando `exit` forma parte de un pipeline o lista de comandos.
//*	Si es así, devuelve true para indicar que no debe imprimirse el mensaje "exit".
//?	Devuelve false cuando `exit` se llama solo y sí debe imprimirse el mensaje.

static bool is_quiet_mode(t_data *data)
{
    t_command   *cmd;

    cmd = data->cmd;
    if (!cmd)
        return (false);
    if (cmd->next != NULL || cmd->prev != NULL)
        return (true);
    return (false);
}

//! - Si se llama solo, imprime "exit" y termina el shell con el código dado (o 0 si no se proporciona).
//? - Si se usa en un pipeline, termina solo el proceso hijo con el código dado, sin cerrar minishell.
//* - Si los argumentos son inválidos, no cierra el shell y devuelve un código de error (1 o 2).

int exit_builtin(t_data *data, char **args)
{
    int     exit_code;
    bool    error;
    bool    quiet;

    quiet = is_quiet_mode(data);
    error = false;
    if (!quiet && data->interactive)
        ft_putendl_fd("exit", 2);
    if (!args || !args[1])
        exit_code = g_last_exit_code;
    else
    {
        exit_code = get_exit_code(args[1], &error);
        if (error)
            exit_code = errmsg_cmd("exit", args[1],
                "numeric argument required", 2);
        else if (args[2])
                return (errmsg_cmd("exit", NULL, "too many arguments", 1));
    }
    exit_shell(data, exit_code);
    return (2);
}