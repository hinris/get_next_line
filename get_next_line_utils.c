/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodrig <anrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:30:45 by anrodrig          #+#    #+#             */
/*   Updated: 2024/05/03 19:08:45 by anrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;
    char    *pdest;

    pdest = dest;
	i = 0;
	while (src[i] != '\0')
		*dest++ = src[i++];
	*dest = '\0';
	return (pdest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(ft_strlen(src) + 1);
	if (!dest)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str1 = (char *)s1;
	str2 = (char *)s2;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (*str1)
		dest[i++] = *str1++;
	while (*str2)
		dest[i++] = *str2++;
	dest[i] = '\0';
	return (dest);
}