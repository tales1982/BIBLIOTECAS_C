/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:38:36 by tlima-de          #+#    #+#             */
/*   Updated: 2024/03/26 17:38:48 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void ft_putchar(char s)
{
	write(1, &s , 1);
}


int	main(int ac, char **av)
{
	int	j;
	char	aux;
	
	j = 0;
	if(ac == 2)
	{
		while(av[1][j] != '\0')
		{
			if(av[1][j] >= 'a' && av[1][j] <= 'z')
			{
				ft_putchar(av[1][j] - 'a' + 'A' );
			}	
			else if(av[1][j] >= 'A' && av[1][j] <= 'Z')
			{
				ft_putchar(av[1][j] - 'A' + 'a' );
			}
			else
				ft_putchar(av[1][j]);
			j++;
		}
		
	}
	write(1, "\n", 1);
	
	return 0;
}
