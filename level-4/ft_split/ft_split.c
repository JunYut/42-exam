# include <stdlib.h>
# include <stdio.h>

int is_space(char c);
void ft_strncpy(char *dst, char *src, int len);
char **ft_split(char *str);

int main(void)
{
	char *src = "	 Hello, how are you ? \n ";
	char **split = ft_split(src);
	int i;

	i = -1;
	while (split[++i])
		printf("[%s]\n", split[i]);
}

char **ft_split(char *str)
{
	char **split;
	int count;
	int start;
	int i;
	int j;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (i == 0 && !is_space(str[i]))
			count += 1;
		else if (!is_space(str[i]) && is_space(str[i - 1]))
			count += 1;
	}
	split = (char **)malloc(sizeof(char *) * (count + 1));
	j = -1;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			++i;
		start = i;
		while (str[i] && !is_space(str[i]))
			++i;
		if (i > start)
		{
			split[++j] = (char *)malloc(i - start + 1);
			ft_strncpy(split[j], &str[start], i - start);
		}
	}
	split[count] = NULL;
	return (split);
}

void ft_strncpy(char *dst, char *src, int len)
{
	int i;

	i = -1;
	while (++i < len)
		dst[i] = src[i];
	dst[i] = '\0';
}

int is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}
