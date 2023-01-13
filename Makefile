# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:44:28 by abiru             #+#    #+#              #
#    Updated: 2023/01/13 11:08:44 by abiru            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ft_atoi.c ft_split.c pw2.c stack.c ps_utils.c rules.c sort_medium.c check_arg.c free.c ft_strlen.c sort_med_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc -g

CFLAGS = -Wextra -Werror -Wall

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re