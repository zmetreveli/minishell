/*
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	token;
		enum test
		{
			True = 1,
			False,
			Three
		};
		if (strcmp("True", av[1]) == 0)
			token = True;
		else if (strcmp("False", av[1]) == 0)
			token = False;
		else if (strcmp("Three", av[1]) == 0)
			token = Three;
		else
		{
			printf("Wtf u on gang\n");
			return (1);
		}
		if (token == True)
			printf("True!\n");
		if (token == False)
			printf("False!\n");
		if (token == Three)
			printf("Three!\n");
//		printf("%d %d %d", True, False, Three);
	}
	else
	{
		printf("Wrong argument count\n");	
		return (1);
	}
}


int	main(void)
{
		const char *prompt = ">>> ";
		char *user_response = readline (prompt);
		printf("My goat '%s' lets gooo\n", user_response);
		free(user_response);
		user_response = readline (prompt);
		printf("command not found: %s\n", user_response);
		free(user_response);
		user_response = readline (prompt);
		if (strcmp(user_response, "env") == 0)
			printf("ENVIROMNETAL PRINTEADA\n");
		else
			printf("command not found: %s\n", user_response);
		return 0;
	//else
	//	return (printf("wrong arguments dummy"), 1);
}
*/