#include "main.h"

char *strcpycat(char *dest, char *str);

/**
 * _which - provides same functionality as which
 * 
 * @ac: # of args
 * @av: poiinter array of args
 * Return: 0 on all cmd found, 1 on 1>= not found, 2 on invalid use
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;
	char *path, *arg, *cmd;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (2);
	}

	/* $PATH - */
	path = strdup(getenv("PATH"));
	arg = strtok(path, ":");
	
	cmd = strcpycat(arg, av[1]);
	if (stat(cmd, &st) == 0)
	{
		printf("%s\n", cmd);
		return (0);
	}
	while (arg != NULL)
	{
		arg = strtok(NULL, ":");
		cmd = strcpycat(arg, av[1]);
		
		if (stat(cmd, &st) == 0)
		{
			printf("%s\n", cmd);
			return (0);
		}
	}
	return (1);
}


char *strcpycat(char *dest, char *str)
{
	char *new_str;
	int i = 0, x = 0;
	new_str = malloc((strlen(dest) + strlen(str) + 2) * sizeof(char));

	if (new_str == NULL)
	{
		/* malloc fail */
		printf("Mallac Fail in: strcpycat()");
		return(NULL);
	}
	
	while (dest[i])
	{
		new_str[i] = dest[i];
		i++;
	}
	new_str[i] = '/';
	i++;
	while(str[x])
	{
		new_str[i + x] = str[x];
		x++;
	}
	new_str[i + x] = '\0';

	return (new_str);
}
