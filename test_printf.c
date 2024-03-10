#include "ft_printf/ft_printf.h"
#include <stdio.h>

int main(void)
{
    char *string = "Hello, world!";
    int number = 123;
    unsigned int unumber = 456;
    void *pointer = &number;

    // Teste de string
     ft_printf("\n***************** STRING ******************\n\n");
    ft_printf("\tNun de caracter: [%d]\n", ft_printf("%s", string));
    

    // Teste de caractere
    ft_printf("\n****************** CARACTER *****************\n\n");
    ft_printf("\tNun de caracter:[%d]\n",ft_printf("%c", 'C'));

    // Teste de ponteiro
    ft_printf("\n****************** POINTER *****************\n\n");
    ft_printf("\tNun de caracter: [%d]\n",ft_printf("%p", pointer));

    // Teste de inteiro
     ft_printf("\n***************** INTERGER *****************\n\n");
    ft_printf("\tNun de caracter:[%d]\n",ft_printf("%d", number));
 
    ft_printf("\n*************** INTERGER (I) ****************\n\n");
    ft_printf("\tNun de caracter: [%d]\n",ft_printf("%i", number));

    // Teste de unsigned
     ft_printf("\n***************** UNSIGNED *****************\n\n");
    ft_printf("\tNun de caracter: [%d]\n",ft_printf("%u", unumber));

    // Teste de hexadecimal (minúsculas)
     ft_printf("\n************* HEX (LOWERCASE) **************\n\n");
    ft_printf("\tNun de caracter: [%d]\n",ft_printf("%x", unumber));

    // Teste de hexadecimal (maiúsculas)
     ft_printf("\n************** HEX (UPPRCASE) **************\n\n");
    ft_printf("\tNun de caracter: [%d]\n",ft_printf("%X", unumber));

    // Teste de porcentagem
     ft_printf("\n**************** PERCENT SIGN **************\n\n");
    ft_printf("\tNun de caracter: [%d]\n",ft_printf("%%"));

    return 0;
}
