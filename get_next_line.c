/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodrig <anrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:26:47 by anrodrig          #+#    #+#             */
/*   Updated: 2024/05/11 16:22:59 by anrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_line(t_list *list)
{
    int str_len;
    char *next_str;

    if (!list)
        return (NULL);
    str_len = len_to_newline(list);
    next_str = malloc(str_len + 1);
    if (!next_str)
        return (NULL);
    copy_str(list, next_str);
    return (next_str);
}

void    append(t_list **list, char *buf)
{
    t_list *new_node;
    t_list *last_node;

    last_node = ft_lstlast(*list);
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    if (!last_node)
        *list = new_node;
    else
        last_node->next = new_node;
    new_node->strbuf = buf;
    new_node->next = NULL;
}

void    create_list(t_list **list, int fd)
{
    int char_read;
    char *buf;
    
    while (!found_newline(*list))
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (!buf)
            return ;
        char_read = read(fd, buf, BUFFER_SIZE);
        if (!char_read)
        {
            free(buf);
            return ;
        }
        buf[char_read] = '\0';
        append(list, buf);
    }
}
char    *get_next_line(int fd)
{
    static t_list   *list;
    char            *next_line;
    
    list = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
        return (NULL);
    create_list(&list, fd);
    if (!list)
        return (NULL);
    next_line = get_line(list);
    polish_list(&list);
    return (next_line);
}

int main(void) {
    
    int fd;
    char *line;
    int lines;
    
    lines = 1;
    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("%d->%s", lines++, line);
    return (0);
}