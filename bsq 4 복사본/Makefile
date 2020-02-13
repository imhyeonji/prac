# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyim <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 23:03:38 by hyim              #+#    #+#              #
#    Updated: 2020/02/13 03:16:00 by kyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFILE = ./

SRCS = ${SRCFILE}main.c\
	   ${SRCFILE}ft_read_file.c\
	   ${SRCFILE}ft_check_char.c\
	   ${SRCFILE}ft_make_index.c\
	   ${SRCFILE}ft_find_bsq.c\
	   ${SRCFILE}ft_fill_map.c

OBJS = ${SRCS:.c=.o}

NAME = bsq

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< -I includes

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all :	${NAME}

clean :
	${RM} ${OBJS}

fclean :	clean
	${RM} ${NAME}

re :	fclean all

