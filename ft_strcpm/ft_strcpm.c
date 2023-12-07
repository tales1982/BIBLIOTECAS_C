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
int	strcpm(char *str1, char *str2);

int	main()
{
	char	s1[] = "Hello";
	char	s2[] = "42 Luxembourg";
	strcpm(s1,s2);
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

int	strcpm(char *str1, char *str2)
{
	int	i;
	int	j;
	
	i = ft_len(str1);
	j = ft_len(str2);
	if(i > j )
	{
		printf("S1 MAIOR = %d",i);

	}
	else if(i < j)
	{
		printf("S2 MAIOR= %d",j);

	}
	else
	{
		printf("S1 = %d\nS2 = %d", i , j);
	}
	i++;

	return (str1 - str2);
}
