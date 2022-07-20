#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait & leave task
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t child_pid;
	int i, status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *arge[] = {NULL};

	for (i = 1; i <= 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, arge);
		}
		else
		{
			wait(&status);
			printf("Process %d) complete\n", i);
		}
	}
	return (0);
}
