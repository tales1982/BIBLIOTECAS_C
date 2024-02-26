/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:27:29 by tlima-de          #+#    #+#             */
/*   Updated: 2024/02/26 19:41:39 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i;
    char *str;

    /* Verificamos primeiro se a string que recebemos não é nula.
     * Se for o caso, retornamos NULL, pois não conseguiremos criar
     * uma substring a partir de algo vazio.
     */
    if (!s)
        return (NULL);

    /* Se o índice de início for maior que o comprimento da string original,
     * retornamos uma string vazia alocada que pode ser liberada posteriormente.
     */
    if (start > ft_strlen(s))
        return (ft_strdup(""));

    /* Se o comprimento que devemos copiar for maior que o comprimento da string
     * a partir do índice de início, isso significa que devemos parar após ler
     * toda a string e que o tamanho alocado não deve ser igual ao comprimento
     * recebido como parâmetro, mas apenas o tamanho que vamos
     * copiar mais um para o caractere de terminação NUL.
     * Isso nos permite alocar apenas a memória realmente necessária.
     */
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);

    /* Em seguida, alocamos a memória.
    */
    str = ft_calloc(len + 1, sizeof(char));
    if (!str)
        return (NULL);

    i = 0;

    /* Em seguida, percorremos a string recebida como parâmetro a partir do índice
     * start + i e copiamos cada caractere para nossa nova string no índice i.
     */
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }

    /* Finalmente, retornamos a substring.
     */
    return (str);
}

