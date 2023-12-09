/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_print_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:43:32 by tlima-de          #+#    #+#             */
/*   Updated: 2023/12/09 12:43:42 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void print_int(int number) {
    char buffer[20]; // Tamanho máximo razoável para um número inteiro
    int index = 0;
    int is_negative = 0;

    // Verifica se o número é negativo
    if (number < 0) {
        is_negative = 1;
        number = -number;
    }

    // Lida com o caso do número ser zero
    if (number == 0) {
        buffer[index++] = '0';
    } else {
        // Converte cada dígito do número para caracteres
        while (number != 0) {
            int digit = number % 10;
            buffer[index++] = digit + '0';
            number /= 10;
        }

        // Se o número for negativo, adiciona o sinal '-'
        if (is_negative) {
            buffer[index++] = '-';
        }

        // Inverte a string para imprimir na ordem correta
        for (int i = 0; i < index / 2; ++i) {
            char temp = buffer[i];
            buffer[i] = buffer[index - i - 1];
            buffer[index - i - 1] = temp;
        }
    }

    // Escreve a sequência de caracteres no console usando a função write
    write(1, buffer, index);
    write(1, "\n", 1);
}

int main() {
    int number = 0; // Seu número inteiro
    
    while(number <= 100)
    {
        print_int(number); // Chama a função para imprimir o número inteiro
    
        number++;
    }
    return 0;
}



