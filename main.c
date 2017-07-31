#include <stdlib.h>
#include <stdio.h>

char	*ullitoa(unsigned long long int n, unsigned int base);
char	*llitoa(long long int n, unsigned int base);

int		main(int argc, char **argv)
{
	if (argc == 3)
		printf("%s\n", llitoa(atoi(argv[1]), atoi(argv[2])));
	else
		printf("usage: ./a.out value base\n");
	return (0);
}
