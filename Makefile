# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodrig <anrodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 18:06:11 by anrodrig          #+#    #+#              #
#    Updated: 2024/05/06 00:44:21 by anrodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= get.a
CC		= cc
CFLAGS 		= -Wall -Werror -Wextra

SRCS = 	get_next_line_utils.c get_next_line.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
