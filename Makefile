# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 17:52:44 by mkim3             #+#    #+#              #
#    Updated: 2022/05/03 22:39:30 by mkim3            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SRCS=./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putnbr_fd.c \
./libft/ft_atoi.c ./libft/ft_strlen.c ./libft/ft_calloc.c \
./libft/ft_strlcat.c ./libft/ft_chrjoin.c
LIBFT_OBJS=$(LIBFT_SRCS:.c=.o)
LIBFT_PATH=./libft

CLIENT=client
CLIENT_SRCS=client.c
CLIENT_OBJS=$(CLIENT_SRCS:.c=.o)

SERVER=server
SERVER_SRCS=server.c
SERVER_OBJS=$(SERVER_SRCS:.c=.o)

GCC=gcc
FALGS=-Wall -Werror -Wextra

TARGET=MINITALK

all:$(TARGET)

.c.o:
	$(CC) $(CFLAGS) -I $(LIBFT_PATH) -c $< -o $@

$(SERVER) : $(LIBFT_OBJS) $(SERVER_OBJS)
	$(GCC) $(FALGS) -I $(LIBFT_PATH) $^ -o $@

$(CLIENT) : $(LIBFT_OBJS) $(CLIENT_OBJS)
	$(GCC) $(FALGS) -I $(LIBFT_PATH) $^ -o $@
	
$(TARGET) : $(SERVER) $(CLIENT)

clean:
	rm $(LIBFT_OBJS) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	rm $(CLIENT) $(SERVER) 

re: fclean all

.PHONY: re fclean clean all