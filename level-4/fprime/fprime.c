#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	number;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	if (atoi(argv[1]) == 1)
	{
		printf("1\n");
		return (0);
	}
	i = 1;
	number = atoi(argv[1]);
	while (number >= ++i)
	{
		if (number % i == 0)
		{
			printf("%d", i);
			if (number == i)
				break ;
			printf("*");
			number /= i;
			i = 1;
		}
	}
	printf("\n");
	return (0);
}
