#include "minishell.h"

parse(char **args)
{
	
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		parse(av);
		return (0)
	}
	else
	{
		printf("Not enough arguments");
		return (1);
	}
}
