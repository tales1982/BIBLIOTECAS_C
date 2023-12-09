/*
  A função atoi() retorna um valor int produzido interpretando
  os caracteres de entrada como um número.
*/
#include <stdio.h>

int	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Uso: %s <string_para_conversao>\n", argv[0]);
		return 1;
	}

	int x = ft_atoi(argv[1]);
	printf("%d\n", x);
	return 0;
}


int	ft_atoi(char *str)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == 'r')
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (num * sign);
}
