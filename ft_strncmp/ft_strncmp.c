/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:08:51 by tlima-de          #+#    #+#             */
/*   Updated: 2023/12/07 17:08:54 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Essa função irá fazer a comparação, caractere a caractere, dos dois parâmetros informados,
 como a função strcmp, exceto por comparar até quantidade caracteres.
*/
 #include <stdio.h>
 
int ft_strlen(char *srt);
int ft_strncmp(char *s1, char *s2, unsigned int n);


int main()
{
	char s1[] = "Hell";
	char s2[] = "Hellkk";
	
	ft_strncmp(s1,s2,3);
}

int ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
termina em casa
}


	
	
			
		






