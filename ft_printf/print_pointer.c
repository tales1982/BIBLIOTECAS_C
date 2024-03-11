/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:55:48 by tlima-de          #+#    #+#             */
/*   Updated: 2024/03/10 18:55:51 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Define uma função estática que aloca uma string para representar um valor unsigned long em hexadecimal
static char *string(unsigned long value, int *strlen) {
    int i; // Variável para contar o número de dígitos hexadecimais
    unsigned long temp; // Variável temporária para manipular o valor
    char *str; // Ponteiro para a string que será alocada

    i = 0; // Inicializa o contador de dígitos
    temp = value; // Inicializa temp com o valor de entrada
    while (temp != 0) // Enquanto temp não for zero
    {
        temp = temp / 16; // Divide temp por 16 para encontrar o próximo dígito hex
        i++; // Incrementa o contador de dígitos
    }
    str = calloc(i + 1, sizeof(char)); // Aloca memória para a string, incluindo espaço para o terminador nulo
    *strlen = i - 1; // Define o comprimento da string como o número de dígitos hexadecimais - 1
    return str; // Retorna o ponteiro para a string alocada
}


// Define uma função para imprimir um valor de ponteiro (endereço de memória)
int print_pointer(unsigned long value, int asc) {
    int count = 0; // Inicializa um contador para o número de caracteres impressos

    if (value == 0) { // Se o valor for zero (ponteiro nulo)
        count += print_string("(nil)"); // Imprime "(nil)" e adiciona o número de caracteres impressos ao contador
        return count; // Retorna o contador de caracteres impressos
    }
   
    unsigned long tempval; // Variável para manipular o valor
    char *printout; // Ponteiro para a string que representará o valor hexadecimal
    int i; // Variável para armazenar o comprimento da string hexadecimal
    int *iptr; // Ponteiro para i

    iptr = &i; // Faz iptr apontar para i
    tempval = value; // Inicializa tempval com o valor de entrada
    printout = string(value, iptr); // Chama a função string para alocar a string hexadecimal e obter seu comprimento

    if (!printout) // Se a alocação falhar
        return (0); // Retorna 0
    while (tempval != 0 && i-- >= 0) // Enquanto ainda houver dígitos hexadecimais para processar
    {
        if ((tempval % 16) < 10) // Se o dígito atual for menor que 10
            printout[i + 1] = (tempval % 16) + '0'; // Converte o dígito para o caractere correspondente e o armazena na string
        else // Se o dígito atual for 10 ou maior
            printout[i + 1] = (tempval % 16) + asc; // Converte o dígito para a letra correspondente (a-f) e o armazena na string
        tempval /= 16; // Prepara tempval para o próximo dígito, dividindo-o por 16
    }

    count += print_string("0x"); // Imprime o prefixo "0x" e adiciona o número de caracteres impressos ao contador
    count += ft_strlen(printout); // Adiciona o comprimento da string hexadecimal ao contador
    ft_putstr_fd(printout, 1); // Imprime a string hexadecimal
    free(printout); // Libera a memória alocada para a string

    return count; // Retorna o contador de caracteres impressos
}
