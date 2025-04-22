/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:02:43 by yudemir           #+#    #+#             */
/*   Updated: 2025/01/14 20:04:32 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remove_line(char *buffer)
{
	char	*cpoint;
	int		i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	cpoint = ft_strdup(&buffer[i + 1]);
	if (!cpoint)
	{
		free(cpoint);
		return (NULL);
	}
	free(buffer);
	return (cpoint);
}

char	*ft_trimline(char *buffer)
{
	char	*endline;
	int		x;

	x = 0;
	if (!buffer)
		return (NULL);
	endline = malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (!endline)
		return (NULL);
	while (buffer[x] != '\n' && buffer[x] != '\0')
	{
		endline[x] = buffer[x];
		x++;
	}
	if (buffer[x] == '\n')
		endline[x++] = '\n';
	endline[x] = '\0';
	return (endline);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;
	int			bytes_read;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = read(fd, temp, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	if (bytes_read < 0 || !buffer || *buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_trimline(buffer);
	buffer = remove_line(buffer);
	return (line);
}
