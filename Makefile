# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:44:28 by abiru             #+#    #+#              #
#    Updated: 2023/01/13 19:23:10 by abiru            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ft_atoi.c ft_split.c push_swap.c ll_utils.c ll_utils2.c ps_utils.c rules.c sort_medium.c check_arg.c free.c ft_strlen.c sort_med_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

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