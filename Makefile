# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acanterg <acanterg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/19 19:18:55 by acanterg          #+#    #+#              #
#    Updated: 2021/07/30 11:42:25 by acanterg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	srcs/ft_atoi.c \
			srcs/ft_concat_c.c \
			srcs/ft_error.c \
			srcs/ft_putchar.c \
			srcs/ft_putnbr.c \
			srcs/ft_putstr.c \
			srcs/ft_strlen.c

SERVER	= server
SERVERC	= server.c
CLIENT	= client
CLIENTC	= client.c
GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCLUD	= -I .
NAME	= minitalk

all : 		$(NAME)

$(NAME) :	$(SERVER) $(CLIENT)

$(SERVER):	
			$(GCC) $(CFLAGS) $(INCLUD) $(SERVERC) $(SRCS) -o $(SERVER)

$(CLIENT):	
			$(GCC) $(CFLAGS) $(INCLUD) $(CLIENTC) $(SRCS) -o $(CLIENT)

clean :
			rm -f $(SERVER) $(CLIENT)

bonus :		all

fclean :	clean

re :		fclean all

.PHONY: 	all clean fclean re bonus