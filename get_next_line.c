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
	if (!*buffer)
		return (NULL);
	endline = malloc((ft_strlen(buffer) + 1) * sizeof(char));
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

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 16)
		return (NULL);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = read(fd, temp, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		temp[bytes_read] = 0;
		buffer = ft_strjoin(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	if (!buffer)
		return (NULL);
	line = ft_trimline(buffer);
	buffer = remove_line(buffer);
	return (line);
}
