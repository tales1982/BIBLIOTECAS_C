/*
As funções strdup() e strndup() são usadas para duplicar uma string.
strdup():
Sintaxe: char * strdup (const char * s);
Esta função retorna um ponteiro para uma string de byte terminada em nulo,
que é uma duplicata da string apontada por s .
A memória obtida é feita dinamicamente usando malloc e, 
portanto, pode ser liberada usando free() .
*/

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{
 	char	*str = "42 Luxembourg";
	char	*dup = ft_strdup(str);

	printf("string src : %s\n", str);
	printf("string dest: %s\n", dup);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	size = i + 1;
	dest = malloc(size);
	if(dest == NULL)
	{
		return (NULL);
	}
	i = 0;
	while(src[i] != '\0' )
	{
		dest[i] =  src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
