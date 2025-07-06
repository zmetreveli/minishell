/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:06:27 by zurabmetrev       #+#    #+#             */
/*   Updated: 2025/07/06 00:45:42 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "../includes/signals.h"
#include "../includes/init.h"
#include "../includes/lexer.h"
#include "../includes/clean_and_exit.h"
#include "../includes/minishell.h"
#include "../includes/structs.h"
#include "../includes/env.h"
#include "../includes/bultins.h"
#include "../includes/minishell.h"
#include "../includes/execution.h"
#include "../includes/parser.h"
#include "../includes/redirection.h"
#include "../libft/libft.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>

int		g_last_exit_code = 0;

void	get_time_prompt(char *buffer, size_t size, t_data *data)
{
	time_t		now;
	struct tm	*local;
	char		*user;
	char		cwd[256];
	char		*color;

	now = time(NULL);
	local = localtime(&now);
	user = get_env_var_value(data->env, "USER");
	if (local->tm_hour < 12)
		color = "\033[1;32m";
	else
		color = "\033[1;33m";
	getcwd(cwd, sizeof(cwd));
	if (user)
		snprintf(buffer, size,
			"\001%s\002[%s@%s %02d:%02d:%02d] ➜ \001\033[0m\002 ",
			color, user, cwd,
			local->tm_hour, local->tm_min, local->tm_sec);
	else
		snprintf(buffer, size,
			"\001%s\002[%s@%s %02d:%02d:%02d] ➜ \001\033[0m\002 ",
			color, "unknown", cwd,
			local->tm_hour, local->tm_min, local->tm_sec);
}

//Comprueba los argumentos de inicio (./minishell o ./minishell -c "comando")
static bool	start_check(t_data *data, int ac, char **av)
{
	if (ac != 1 && ac != 3)
		return (usage_message(false));
	if (ac == 3)
	{
		data->interactive = false;
		if (!av[1] || (av[1] && ft_strcmp(av[1], "-c") != 0))
			return (usage_message(false));
		else if (!av[2] || (av[2] && av[2][0] == '\0'))
			return (usage_message(false));
	}
	else
		data->interactive = true;
	return (true);
}

//Modo no interactivo: ejecuta comandos dados por argumento (separados por ';')

void	minishell_noninteractive(t_data *data, char *arg)
{
	char	**user_inputs;
	int		i;

	user_inputs = ft_split(arg, ';');
	if (!user_inputs)
		exit_shell(data, EXIT_FAILURE);
	i = 0;
	while (user_inputs[i])
	{
		data->user_input = ft_strdup(user_inputs[i]);
		if (parse_user_input(data) == true)
			g_last_exit_code = execute(data);
		else
			g_last_exit_code = 1;
		i++;
		free_data(data, false);
	}
	free_str_tab(user_inputs);
}

//todo/  Modo interactivo: loop que pide input y ejecuta comandos

void	minishell_interactive(t_data *data)
{
	char	prompt[256];

	while (1)
	{
		set_signals_interactive();
		get_time_prompt(prompt, sizeof(prompt), data);
		data->user_input = readline(prompt);
		set_signals_noninteractive();
		if (parse_user_input(data) == true)
			g_last_exit_code = execute(data);
		else
			g_last_exit_code = 1;
		free_data(data, false);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.env = env;
	if (!start_check(&data, ac, av) || !init_data(&data, env))
		exit_shell(NULL, EXIT_FAILURE);
	init_shlvl(&data);
	if (data.interactive)
		minishell_interactive(&data);
	else
		minishell_noninteractive(&data, av[2]);
	exit_shell(&data, g_last_exit_code);
	return (0);
}
