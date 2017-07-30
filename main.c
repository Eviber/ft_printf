#include <stdlib.h>
#include <stdio.h>

char	*ullitoa(unsigned long long int n);

int		main(int argc, char **argv)
{
	unsigned long long int n = 18446744073709551615;

	printf("%s\n", ullitoa(n));
	return (0);
}
