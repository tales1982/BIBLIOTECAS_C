/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:36:40 by tlima-de          #+#    #+#             */
/*   Updated: 2023/12/07 15:36:43 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 A função strlen() tem como argumento um string. Ela retorna um inteiro que é 
 o comprimento do string (o número de caracteres do string,
 não contando o caractere NULL). Por exemplo, o comprimento do string ``alo'' é 3.
*/
#include <stdio.h>

int ft_strlen(char *str);

int main(void)
{
	char name[] = "42 Luxembourg";//13 caracter avec space
	
	printf("%d",ft_strlen(name));
}

int ft_strlen(char *str)
{
	int	count;
	
	count = 0;
	while(str[count] != '\0')
	{
		count++;
	}
	return (count);
}


