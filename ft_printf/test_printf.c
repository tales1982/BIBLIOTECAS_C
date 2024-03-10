#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
    char *string = "Hello, world!";
    int number = 123;
    unsigned int unumber = 456;
    void *pointer = &number;

    // Teste de string
    ft_printf("Nun de caracter: %d\n", ft_printf("String: %s\t", string));
    

    // Teste de caractere
    ft_printf("Nun de caracter: %d\n",ft_printf("Character: %c\t", 'C'));

    // Teste de ponteiro
    ft_printf("Nun de caracter: %d\n",ft_printf("Pointer: %p\t", pointer));

    // Teste de inteiro
    ft_printf("Nun de caracter: %d\n",ft_printf("Integer: %d\t", number));
    ft_printf("Nun de caracter: %d\n",ft_printf("Integer (i): %i\t", number));

    // Teste de unsigned
    ft_printf("Nun de caracter: %d\n",ft_printf("Unsigned: %u\t", unumber));

    // Teste de hexadecimal (minúsculas)
    ft_printf("Nun de caracter: %d\n",ft_printf("Hex (lowercase): %x\t", unumber));

    // Teste de hexadecimal (maiúsculas)
    ft_printf("Nun de caracter: %d\n",ft_printf("Hex (uppercase): %X\t", unumber));

    // Teste de porcentagem
    ft_printf("Nun de caracter: %d\n",ft_printf("Percent sign: %%\t"));

    return 0;
}
