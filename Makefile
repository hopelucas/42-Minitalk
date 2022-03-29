# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlucas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 13:05:02 by hlucas            #+#    #+#              #
#    Updated: 2022/03/29 13:15:55 by hlucas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: libft all bonus clean fclean re

NAME_SV = server
NAME_CL = client
NAME_SV_B = server_bonus
NAME_CL_B = client_bonus

SRCS_SV = ./servers/server.c
SRCS_CL = ./clients/client.c
OBJS_SV = $(SRCS_SV:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o)

SRCS_SV_B =	./servers/server_bonus.c
SRCS_CL_B =	./clients/client_bonus.c
OBJS_SV_B = $(SRCS_SV_B:.c=.o)
OBJS_CL_B = $(SRCS_CL_B:.c=.o)

GCC_FLAG = -Wall -Werror -Wextra
CC = gcc $(GCC_FLAG)

all: $(NAME_SV) $(NAME_CL)

libft:
	make bonus -C libft/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME_SV): libft $(OBJS_SV)
	$(CC) -o $@ $(OBJS_SV) -Llibft -lft -I./includes

$(NAME_CL): libft $(OBJS_CL)
	$(CC) -o $@ $(OBJS_CL) -Llibft -lft -I./includes


bonus: $(NAME_SV_B) $(NAME_CL_B)

$(NAME_SV_B): libft $(OBJS_SV_B)
	$(CC) -o server $(OBJS_SV_B) -Llibft -lft -I./includes

$(NAME_CL_B): libft $(OBJS_CL_B)
	$(CC) -o client $(OBJS_CL_B) -Llibft -lft -I./includes

clean:
	rm -f servers/*.o
	rm -f clients/*.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME_SV) $(NAME_CL) $(NAME_SV_B) $(NAME_CL_B)
	make -C libft/ fclean

re: fclean all
