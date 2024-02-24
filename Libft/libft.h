/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:00:09 by tlima-de          #+#    #+#             */
/*   Updated: 2024/02/24 14:04:32 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H_INCLUDED
# define LIBFT_H_INCLUDED

# include <unistd.h>
# include <stdlib.h>

int	ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	ft_isprint(int c);
int	ft_isdigit(int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
int	ft_str_is_uppercase(char *str);
int	ft_str_is_lowercase(char *str);
char	*ft_strrchr(const char *s, int c);
#endif
