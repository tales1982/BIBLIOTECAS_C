/*
A função isalnum é utilizada em muitas linguagens de programação para verificar se um caractere é alfanumérico,
ou seja, se é uma letra (maiúscula ou minúscula) ou um número. 
Ela retorna true se o caractere for alfanumérico e false caso contrário. 
É útil para validação de entradas de texto, por exemplo, para garantir que uma senha contenha apenas letras e números.
*/

#include <stdio.h>

int ft_isalnum(int c);

int main() {
    char str[]= "Tales21";
    int nb = 12;
    int i = 0;
    
    while(str[i] != '\0')
    {
         printf("%d\n",ft_isalnum(str[i]));
         i++;
    }
   
    printf("%d\n",ft_isalnum(nb));
    return 0;
}

int	ft_isalnum(int	c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}
