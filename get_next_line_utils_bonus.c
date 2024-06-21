/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodrig <anrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:30:45 by anrodrig          #+#    #+#             */
/*   Updated: 2024/06/21 06:15:47 by anrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int		found_newline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->strbuf[i] && i < BUFFER_SIZE)
		{
			if (list->strbuf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}	
	return (0);
}

int		len_to_newline(t_list *list)
{
	int i;
	int len;
	
	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->strbuf[i])
		{
			if (list->strbuf[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

void	copy_str(t_list *list, char *str)
{
	int i;
	int j;
	
	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->strbuf[i])
		{
			if (list->strbuf[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = list->strbuf[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

void	ft_clean(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->strbuf);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->strbuf[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}


void    polish_list(t_list **list)
{
    t_list *last_node;
    t_list *clean_node;
    int i;
    int j;
    char *buf;

    buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
    if (!buf || !clean_node)
        return ;
    last_node = ft_lstlast(*list);
	i = 0;
    j = 0;
    while (last_node->strbuf[i] && last_node->strbuf[i] != '\n')
        ++i;
    while (last_node->strbuf[i] && last_node->strbuf[++i])
        buf[j++] = last_node->strbuf[i];
    buf[j] = '\0';
    clean_node->strbuf = buf;
    clean_node->next = NULL;
    ft_clean(list, clean_node, buf);
}