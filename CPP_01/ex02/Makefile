# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 11:39:57 by rmazurit          #+#    #+#              #
#    Updated: 2022/11/24 23:32:43 by amenra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	string

CC		= 	c++
RM		= 	rm -f
FLAGS	= 	-Wall -Wextra -Werror -std=c++98
SRC 	=	main.cpp \

OBJ		=	$(addprefix obj/,$(SRC:.cpp=.o))

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

all: ${NAME}

obj/%.o: %.cpp | obj
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

obj:
	mkdir obj

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}
	rm -rf obj

re: fclean all

.PHONY: all clean fclean re
