/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ######.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:19:19 by tales             #+#    #+#             */
/*   Updated: 2023/12/15 16:58:31 by tales            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

char *ft_strcpy(char *s1, char *s2)
{
  size_t i;

  i = 0;
  while(s2[i] != '\0')
  {
    s1[i] = s2[i];
    i++;
  }
  s1[i] = '\0';
  return(s1);
}
