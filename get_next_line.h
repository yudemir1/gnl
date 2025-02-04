#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*ft_trimline(char *buffer);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
