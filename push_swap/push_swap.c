/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:47:14 by tlima-de          #+#    #+#             */
/*   Updated: 2024/04/24 18:47:21 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <string.h>  //para ussar mencpy remover depois e adciona minha lib

/**Vou criar uma macro Depois jogar pra .h*/
#define DIGIT(X) (X / div ) % base


void counting_sort(int *v, int n,int div, int base, int *temp)
{
    int i;
    int t;
    int c[base];
    int acum;

    acum = 0;
    i = 0;
    t = 0;
    memset(c, 0, base * sizeof(int));//utilizar minha funcao depois
    while(i < n)
    {
        c[DIGIT(v[i])];
        i++;
    }
    i = 0;
    while(i < base)
    {
        t = c[i];
        c[i] = acum;
        acum += t;
        i++;
    }
   for(i = 0; i < n; i++ )
   {
    temp[c[DIGIT(v[i])]] = v[i];
    c[DIGIT(v[i])]++;
   }
    memcpy(v, temp, sizeof(int)*n);
}

void radix_sort(int *v, int n)
{
    int k;
    int div;
    int *temp;

    div = 1;
    k = max(v, n);
    *temp = malloc(sizeof(int) * n);
    while(k > 0)
    {
        counting_sort(v, n, div, 10, temp);
        div *= 10;
        k /= 10;
    }
    free(temp);
}

