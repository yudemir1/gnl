/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:02:48 by yudemir           #+#    #+#             */
/*   Updated: 2025/01/14 17:48:04 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
