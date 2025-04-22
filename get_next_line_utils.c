/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yudemir <yudemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:02:45 by yudemir           #+#    #+#             */
/*   Updated: 2025/01/14 18:21:07 by yudemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (!s[i])
		return (NULL);
	else
		return (&s[i]);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (ptr);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
