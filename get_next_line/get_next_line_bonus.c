/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlima-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:54:26 by tlima-de          #+#    #+#             */
/*   Updated: 2024/03/21 18:54:28 by tlima-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int int_fd, char *full_line)
{
	char	*buffer;
	int		nbr_bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!full_line)
	{
		full_line = malloc(1);
		full_line[0] = '\0';
	}
	nbr_bytes_read = 1;
	while (nbr_bytes_read != 0)
	{
		nbr_bytes_read = read(int_fd, buffer, BUFFER_SIZE);
		if (nbr_bytes_read == -1)
			return (0);
		buffer[nbr_bytes_read] = '\0';
		full_line = ft_strjoin(full_line, buffer);
		if (ft_strchr(full_line, '\n'))
			break ;
	}
	free(buffer);
	return (full_line);
}

static char	*ft_return_line(char *full_line)
{
	int		i;
	char	*line_2b_printed;

	i = 0;
	line_2b_printed = "";
	if (!full_line)
		return (NULL);
	while (full_line[i] && full_line[i] != '\n')
		i++;
	line_2b_printed = malloc((i + 2) * 1);
	if (!line_2b_printed)
		return (NULL);
	i = 0;
	while (full_line[i] && full_line[i] != '\n')
	{
		line_2b_printed[i] = full_line[i];
		i++;
	}
	if (full_line[i] == '\n')
	{
		line_2b_printed[i] = full_line[i];
		i++;
	}
	line_2b_printed[i] = '\0';
	return (line_2b_printed);
}

static char	*ft_keep_rest(char *full_line)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (full_line[i] && full_line[i] != '\n')
		i++;
	if ((full_line[i] == '\n' && full_line[i + 1] == '\0') || !full_line[i])
	{
		free(full_line);
		return (NULL);
	}
	rest = malloc((ft_strlen(full_line) - i + 1) * 1);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (full_line[i])
		rest[j++] = full_line[i++];
	rest[j] = '\0';
	free(full_line);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*full_line[MAX_FD];
	char		*line_2b_printed;

	line_2b_printed = "";
	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	full_line[fd] = ft_read(fd, full_line[fd]);
	if (!*full_line[fd])
	{
		free(full_line[fd]);
		full_line[fd] = NULL;
		return (NULL);
	}
	line_2b_printed = ft_return_line(full_line[fd]);
	full_line[fd] = ft_keep_rest(full_line[fd]);
	return (line_2b_printed);
}
