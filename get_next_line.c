/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodrig <anrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:26:47 by anrodrig          #+#    #+#             */
/*   Updated: 2024/05/06 00:43:50 by anrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char     *free_buffers(char *buff1, char *buff2)
{
    free(buff1);
    free(buff2);
    buff2 = NULL;
    return (buff2);
}

static size_t   find_next_break(char *str, size_t i)
{
    char *ptr;

    ptr = str + i;
    while (*ptr && *ptr != '\n')
        ptr++;
    if (*ptr == '\n')
        ptr++;
    return (ptr - str);
}

static char *read_line(char *str)
{
    char *line;
    size_t  i;

    i = 0;
    if (!str || !*str)
        return (NULL);
    i = find_next_break(str, i);
    line = (char *)malloc(sizeof(char) * i + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}
static char     *new_substring(char *str)
{
    char *new;
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    if (!*str)
        return (free(str), NULL);
    i = find_next_break(str, i);
    new = (char *)malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
    if (!new)
        return (free(str), NULL);
    while (str[i] != '\0')
        new[j++] = str[i++];
    new[j] = '\0';
    if (!*new)
        return (free(str), free(new), NULL);
    free(str);
    return (new);
}

char    *get_next_line(int fd)
{
    char        *read_cont;
    int         read_bytes;
    static char *read_buff;

    read_bytes = 1;
    if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
        return (NULL);
    read_cont = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!read_cont)
        return (NULL);
    while (!(ft_strchr(read_buff, '\n')) && read_bytes != 0)
    {
        read_bytes = read(fd, read_cont, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            read_buff = free_buffers(read_cont, read_buff);
            return (NULL);
        }
        *(read_cont + read_bytes) = '\0';
        read_buff = ft_strjoin(read_buff, read_cont);
    }
    free(read_cont);
    read_cont = read_line(read_buff);
    read_buff = new_substring(read_buff);
    return (read_cont);
}

int main(void)
{
    int file_descriptor = open("test.txt", O_RDONLY);
    char* line = get_next_line(file_descriptor);

    // Process the line

    // Free the memory allocated for the line
    free(line);

    close(file_descriptor);
    return (0);
}