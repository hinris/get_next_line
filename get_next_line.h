/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodrig <anrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:44:35 by anrodrig          #+#    #+#             */
/*   Updated: 2024/10/29 18:43:17 by anrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GETGET_NEXT_LINE_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//# define BUFFER_SIZE 10

# define OPEN_MAX 1024

char    *get_next_line(int fd);
int ft_breakline(char *buffer);
int ft_strlen(char *str);
char *ft_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2);
char *ft_strcut(char *line, char *buffer);

#endif