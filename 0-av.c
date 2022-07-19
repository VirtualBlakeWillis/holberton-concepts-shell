#include "main.h"

int main(int ac __attribute__((unused)), char **av)
{
	while (*av)
	{
		printf("%s\n", *av);
		*av++;
	}
	return (0);
}
