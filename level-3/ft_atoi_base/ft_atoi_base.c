# include <stdio.h>

int ft_atoi_base(const char *str, int str_base);
char lower(char c);

int main(void)
{
	char *str = "FF";
	int str_base = 16;
	printf("%d\n", ft_atoi_base(str, str_base));

	str = "101";
	str_base = 2;
	printf("%d\n", ft_atoi_base(str, str_base));

	str = "101";
	str_base = 10;
	printf("%d\n", ft_atoi_base(str, str_base));

	str = "101";
	str_base = 8;
	printf("%d\n", ft_atoi_base(str, str_base));

	str = "101";
	str_base = 16;
	printf("%d\n", ft_atoi_base(str, str_base));

	str = "-101";
	str_base = 2;
	printf("%d\n", ft_atoi_base(str, str_base));

	str = "-101";
	str_base = 10;
	printf("%d\n", ft_atoi_base(str, str_base));

	str = "-101";
	str_base = 8;
	printf("%d\n", ft_atoi_base(str, str_base));

	str = "-101";
	str_base = 16;
	printf("%d\n", ft_atoi_base(str, str_base));
	return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;
	int i;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	result = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * str_base + str[i] - '0';
		else if (lower(str[i]) >= 'a' && lower(str[i]) <= 'f')
			result = result * str_base + lower(str[i]) - 'a' + 10;
		else
			break ;
	}
	return (result * sign);
}

char lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ' ');
	return (c);
}
