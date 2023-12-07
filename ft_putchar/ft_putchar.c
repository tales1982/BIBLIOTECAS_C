/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:06:09 by tlima-de          #+#    #+#             */
/*   Updated: 2023/12/07 15:10:16 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 Esta função é uma maneira simplificada de se mostrar um único caractere na tela. 
 O argumento passado será convertido para caractere e mostrado na tela.
*/

#include <unistd.h>

void ft_putchar(char *str);

int main(void)
{
  char name[] = "Hello World!";
  	ft_putchar(name);
}

void ft_putchar(char *str)
{
	int	i;
	
	i = 0;
	while(str[i] != '\0')
	{
		write(1 ,&str[i], 1);
		i++;
	}
}


