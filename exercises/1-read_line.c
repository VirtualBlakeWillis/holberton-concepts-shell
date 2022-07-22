#include "main.h"

int main(int ac, char **av)
{
	size_t buffsize;
	char *buff;

	printf("$ ");
	getline(&buff, &buffsize, stdin);
	printf("%s", buff);

	return (0);
}
