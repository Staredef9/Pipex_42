# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 12:24:30 by fsalvett          #+#    #+#              #
#    Updated: 2023/03/12 13:35:36 by fsalvett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c parents.c

OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME} 

${NAME}: ${OBJS}
	make all -C Libft
	mv ./Libft/libft.a ./
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} libft.a
	
clean: libftclean 
	${RM} ${OBJS} libft.a
fclean: clean
	${RM} ${NAME}
re: fclean all

libftclean: 
	cd Libft && ${MAKE} clean

.PHONY: all clean fclean re .c.o. libft
.SUFFIXES: .c .o
