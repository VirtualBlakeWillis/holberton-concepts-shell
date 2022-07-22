#include "main.h"

int command(char *cmd);
int count_args(char *str);
void tokenize_string(char *buff);
char *prep_string(char *cmd);
/**
 * main - simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	size_t buffsize;
	char *buff, cmd;
	int i = 0, num_args, x;
	while (1)
	{
		printf("#concept-shell$ ");

		getline(&buff, &buffsize, stdin);

		if (strcmp(buff, "exit\n") == 0)
			break;
		else
		{
			command(buff);
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * command - execute command in child process
 *
 * Return: 0 on success, -1 on failure
 */
int command(char *cmd)
{
	pid_t my_pid;
	char *argv[] = {cmd, NULL};

	my_pid = fork();
	if (my_pid == -1)
	{
		/* error */
		return (EXIT_FAILURE);
	}

	if (my_pid == 0)
	{
		/* child */
		execve(argv[0], argv, NULL);
	}
	else
	{
		wait(NULL);
		/* parent */
	}
	return (EXIT_SUCCESS);
}

char *prep_string(char *cmd)
{
	int i = 0;

	while (cmd[i] == ' ')
		i++;

	for (; i < strlen(cmd); i++)
	{
		if (cmd[i] == ' ' || cmd[i] == '\0')
		{
			cmd[i] = '\0';
			return (cmd);
		}
	}
	return (cmd);
}
/**
 * tokenize_string - populate *argv[] with arguments
 * @buff: command line input from user
 * Return: void
 */

void tokenize_string(char *buff)
{
	char *argument;
	int i = 0;
	argument = strtok(buff, " ");

	while (argument != NULL)
	{
		argument = strtok(NULL, " \0");
		i++;
	}
}

/**
 * count_args - count # of args in string
 * @str: command line input from user
 *
 * Return: Number of args found
 */
int count_args(char *str)
{
	int i = 0, n = 0;
	char temp;

	while (str[i] == ' ') /* iterates past spaces at start of string*/
		i++;
	for (; i < strlen(str); i++)
	{
		if (str[i] == ' ' && str[i - 1] != ' ' && str[i + 1] != ' ')
			n++;
		/* arguments wrapped in quotes are counted as 1 argument
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				if (str[i] == '\0')
				{
					printf("Error: unclosed puncuation mark in input\n");
					return (-1);
				}
				i++;
			}
		} */
	}
	n++;
	return (n);
}