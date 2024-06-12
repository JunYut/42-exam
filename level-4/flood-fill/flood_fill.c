#include <stdlib.h>
#include <stdio.h>

typedef struct s_point
{
	int x;
	int y;
} t_point;

char** make_area(char** zone, t_point size);
void  flood_fill(char **tab, t_point size, t_point begin);

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111110",
		"00101001",
		"10010000",
		"00100001",
		"11101001",
	};
	char *zone2[] = {
		"1",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);

	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	(void)zone;
	(void)zone2;
	return (0);
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int is_target(char c, char target)
{
	if (c == target || c == 'F')
		return (1);
	return (0);
}
int check_wall(char **tab, t_point size, t_point coord, char target)
{
	int x;
	int y;

	x = coord.x;
	y = coord.y;
	target = tab[y][x];
	// Corner cases
	if (x == 0 && y == 0)
	{
		if (is_target(tab[y + 1][x], target) || is_target(tab[y][x + 1], target))
			return (1);
		else
			return (0);
	}
	if (x == size.x - 1 && y == 0)
	{
		if (is_target(tab[y + 1][x], target) || is_target(tab[y][x - 1], target))
			return (1);
		else
			return (0);
	}
	if (x == 0 && y == size.y - 1)
	{
		if (is_target(tab[y - 1][x], target) || is_target(tab[y][x + 1], target))
			return (1);
		else
			return (0);
	}
	if (x == size.x - 1 && y == size.y - 1)
	{
		if (is_target(tab[y - 1][x], target) || is_target(tab[y][x - 1], target))
			return (1);
		else
			return (0);
	}

	// Side cases
	if (x == 0)
	{
		if (is_target(tab[y - 1][x], target) || is_target(tab[y + 1][x], target)
			|| is_target(tab[y][x + 1], target))
			return (1);
		else
			return (0);
	}
	if (x == size.x - 1)
	{
		if (is_target(tab[y - 1][x], target) || is_target(tab[y + 1][x], target)
			|| is_target(tab[y][x - 1], target))
			return (1);
		else
			return (0);
	}
	if (y == 0)
	{
		if (is_target(tab[y][x - 1], target) || is_target(tab[y][x + 1], target)
			|| is_target(tab[x][y + 1], target))
			return (1);
		else
			return (0);
	}
	if (y == size.y - 1)
	{
		if (is_target(tab[y][x - 1], target) || is_target(tab[y][x + 1], target)
			|| is_target(tab[y - 1][x], target))
			return (1);
		else
			return (0);
	}

	// Normal cases
	if (is_target(tab[y - 1][x], target) || is_target(tab[y + 1][x], target)
		|| is_target(tab[y][x - 1], target) || is_target(tab[y][x + 1], target))
		return (1);
	else
		return (0);
	return (0);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char target;
	int	i;
	int j;

	if (begin.x < 0 || begin.x > size.x - 1
		|| begin.y < 0 || begin.y > size.y - 1)
		return ;
	target = tab[begin.y][begin.x];
	printf("target: %c\n", target);
	i = -1;
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
		{
			if (tab[i][j] == target)
			{
				if (check_wall(tab, size, (t_point){j, i}, tab[i][j]))
					tab[i][j] = 'F';
			}
		}
	}
}

// void	fill(char **tab, t_point size, t_point cur, char to_fill)
// {
// 	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
// 		return;
// 	tab[cur.y][cur.x] = 'F';
// 	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
// }

// void	flood_fill(char **tab, t_point size, t_point begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }

