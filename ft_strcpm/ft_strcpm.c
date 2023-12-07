/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:09:26 by tlima-de          #+#    #+#             */
/*   Updated: 2023/12/07 16:12:56 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 A função strcmp compara duas strings e devolve um valor inteiro que lhe diz qual
 das strings vem antes no código ASCII: Sintaxe: strcmp (string1, string2);
 */

#include <stdio.h>

int	ft_len(char *str);
int	ft_strcpm(char *str1, char *str2);

int	main()
{
	char	s1[] = "Hello";
	char	s2[] = "42 Luxembourg";
	ft_strcpm(s1,s2);
}

int	ft_len(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);

}


int ft_strcpm(char *str1, char *str2) 
{
	int	i;
	
	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			printf("As strings são diferentes.\n");
			return -1; // Retorna um valor indicando que as strings são diferentes
		}
	i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		printf("As strings são iguais.\n");
		return 0; // Retorna 0 indicando que as strings são iguais
	}
	else
	{
		printf("As strings são de tamanhos diferentes.\n");
		return 1; // Retorna um valor indicando que as strings têm tamanhos diferentes
	}
}
