/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:51:42 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 17:57:40 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "../../includes/bultins.h"
#include "../../includes/clean_and_exit.h"
#include "../../includes/env.h"
#include "../../includes/execution.h"
#include "../../includes/expancion.h"
#include "../../includes/init.h"
#include "../../includes/lexer.h"
#include "../../includes/minishell.h"
#include "../../includes/parser.h"
#include "../../includes/redirection.h"
#include "../../includes/signals.h"
#include "../../includes/structs.h"
#include "../../libft/libft.h"

int	count_rows(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	**copy_2d_arr(char **src)
{
	char	**dest;
	int		i;
	int		rows;
	int		len;

	rows = count_rows(src);
	dest = malloc(sizeof(char *) * (rows + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		len = strlen(src[i]) + 1;
		dest[i] = malloc(sizeof(char) * len);
		if (!dest[i])
		{
			while (--i >= 0)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
		strncpy(dest[i], src[i], len);
	}
	dest[i] = NULL;
	return (dest);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	bubble_sort(char **arr, int n)
{
	int		i;
	int		j;
	int		swapped;
	char	*tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		swapped = 0;
		while (j < n - i - 1)
		{
			if (strcmp(arr[j], arr[j + 1]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

void	print_export(char **envp)
{
	int		i;
	int		size;
	char	**envp_copy;
	char	*equals;

	i = 0;
	size = 0;
	envp_copy = copy_2d_arr(envp);
	size = count_rows(envp);
	bubble_sort(envp_copy, size);
	while (envp_copy[i])
	{
		equals = strchr(envp_copy[i], '=');
		if (equals)
		{
			*equals = '\0';
			if (*(equals + 1) != '\0')
				printf("declare -x %s=\"%s\"\n", envp_copy[i], equals + 1);
			else
				printf("declare -x %s\n", envp_copy[i]);
			*equals = '=';
		}
		i++;
	}
	free_2d_array(envp_copy);
}
