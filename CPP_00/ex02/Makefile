# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 11:39:57 by rmazurit          #+#    #+#              #
#    Updated: 2022/11/23 11:16:20 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	account

CC		= 	c++
RM		= 	rm -f
FLAGS	= 	-Wall -Wextra -Werror -std=c++98
SRC 	=	tests.cpp Account.cpp \

OBJ		=	$(addprefix obj/,$(SRC:.cpp=.o))
DEP 	= 	${addprefix dep/,$(SRC:.cpp=.d)}

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

all: ${NAME}

obj/%.o: %.cpp | obj
	$(CC) -c $(FLAGS) -MMD -MP $(INC) $< -o $@

obj:
	mkdir obj

clean:
	${RM} ${OBJ} ${DEP}

fclean: clean
	${RM} ${NAME}
	rm -rf obj

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
