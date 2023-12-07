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
 

int ft_strncmp(char *s1, char *s2, unsigned int n) {
    while (n > 0 && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
        n--;
    }
    
    if (n == 0) {  // Chegou ao final da comparação
        return 0;
    } else {
        return *(unsigned char *)s1 - *(unsigned char *)s2;
    }
}

int main() {
    char s1[] = "Hello00";
    char s2[] = "Helxlo0";

    int result = ft_strncmp(s1, s2, 2);
    printf("Resultado da strncmp: %d\n", result);

    return 0;
}


	
	
			
		






