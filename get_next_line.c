/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodrig <anrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:47:35 by anrodrig          #+#    #+#             */
/*   Updated: 2024/10/29 18:44:49 by anrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    int  bytes;
    char *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
        return (NULL);
    line = NULL;
    if (buffer[0] != '\0')
        line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
    while (ft_breakline(line) == -1)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes] = '\0';
        if(bytes == 0)
            return (line);
        if(bytes < 0)
            return (free(line), NULL);
        line = ft_strjoin(line, buffer, ft_strlen(line), ft_strlen(buffer));
    }
    return (ft_strcut(line, buffer));
}