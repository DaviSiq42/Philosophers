# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 16:06:37 by davioliv          #+#    #+#              #
#    Updated: 2024/08/28 16:06:38 by davioliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = philo.c utils.c set_stuff.c routine.c
OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

all:	${NAME}

$(NAME):	${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re

//.SILENT:
