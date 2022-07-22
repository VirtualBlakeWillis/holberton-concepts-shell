#include "../main.h"

int main(void)
{
	char *token;
	char str[100] = "Hello World I have Less Worlds";

	token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s ", token);
		token = strtok(NULL, " ");
	}

	return (0);
}
