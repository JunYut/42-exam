# include <stdlib.h>
# include <unistd.h>

int ft_strlen(char *s);

int main(int ac, char **av)
{
	int last;
	int start;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	last = ft_strlen(av[1]) - 1;
	while (last >= 0)
	{
		if (av[1][last] == ' ')
			--last;
		while (last >= 0 && av[1][last] != ' ')
			--last;
		start = last + 1;
		while (av[1][start] && av[1][start] != ' ')
			write(1, &av[1][start++], 1);
		if (last > 0)
			write(1, " ", 1);
	}
}

int ft_strlen(char *s)
{
	int i;

	i = -1;
	while (s[++i]);
	return (i);
}
