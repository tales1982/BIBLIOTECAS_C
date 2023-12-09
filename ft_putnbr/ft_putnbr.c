/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:36:16 by tlima-de          #+#    #+#             */
/*   Updated: 2023/12/09 13:47:21 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int n);

int main(int argc, char **argv) {
    int n = -123; // Seu número inteiro

    ft_putnbr(n);
    write(1, "\n", 1); // Adiciona uma quebra de linha após a impressão do número
    return 0;
}

void ft_putnbr(int n) {
    if (n < 0) {
        write(1, "-", 1); // Adiciona o sinal '-' se o número for negativo
        n = -n; // Torna o número positivo para continuar a impressão
    }

    if (n >= 10) {
        ft_putnbr(n / 10); // Chama recursivamente para imprimir os dígitos restantes
    }

    char digit = n % 10 + '0'; // Converte o dígito para o caractere ASCII correspondente
    write(1, &digit, 1); // Escreve o caractere no terminal
}

