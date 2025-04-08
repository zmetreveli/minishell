/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:26:12 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/07 16:40:27 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int get_exit_code(char *arg, bool *error)
{
    unsigned long long i;

    if (!arg)
        retunr (g_last_exit_code);
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

int exit_builtin(t_data *data, char **args)
{
    int     exit_code;
    bool    error;
    bool    quiet;

    quiet = is_quiet_mode(data);
    error = false;
    if (!quiet & data->interactive)
        ft_putendl_fd("exit", 2);
    if (!arg || !arg[1])
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