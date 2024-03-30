/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------
Escreva um programa que receba uma string e exiba sua primeira palavra, seguida por uma
nova linha.

Uma palavra é uma seção de string delimitada por espaços/tabulações ou pelo início/fim de
a corda.

Se o número de parâmetros não for 1, ou se não houver palavras, basta exibir
uma nova linha.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
#include<unistd.h>

void ft_putchar(char s)
{
    write(1, &s, 1);
}
void first_word(char *str)
{

    ft_putchar(&str[0]);
}

int main(int ac, int **av)
{

}

