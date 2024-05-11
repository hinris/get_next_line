/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodrig <anrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:27:07 by anrodrig          #+#    #+#             */
/*   Updated: 2024/05/11 16:24:05 by anrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

typedef struct s_list
{
    char            *strbuf;
    struct s_list   *next;
}               t_list;

char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
int		len_to_newline(t_list *list);
void	copy_str(t_list *list, char *str);
int		found_newline(t_list *list);
void	ft_clean(t_list **list, t_list *clean_node, char *buf);
void    polish_list(t_list **list);
char    *get_line(t_list *list);
void    append(t_list **list, char *buf);
void    create_list(t_list **list, int fd);

#endif
