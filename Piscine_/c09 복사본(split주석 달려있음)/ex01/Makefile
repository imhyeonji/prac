# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyim <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 21:50:59 by hyim              #+#    #+#              #
#    Updated: 2020/02/11 18:29:11 by hyim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFILE = ./

SRCS = ${SRCFILE}ft_putchar.c ${SRCFILE}ft_swap.c ${SRCFILE}ft_putstr.c ${SRCFILE}ft_strlen.c ${SRCFILE}ft_strcmp.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all :	${NAME}

clean :
	${RM} ${OBJS}

fclean :	clean
	${RM} ${NAME}

re :	fclean all
