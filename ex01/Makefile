# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 11:39:57 by rmazurit          #+#    #+#              #
#    Updated: 2022/11/20 17:03:12 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	phonebook

CC		= 	c++
RM		= 	rm -f
FLAGS	= 	-Wall -Wextra -Werror -std=c++98
SRC 	= 	main.cpp Contacts.cpp PhoneBook.cpp\

OBJ		=	$(addprefix obj/,$(SRC:.cpp=.o))
DEP 	= 	${addprefix dep/,$(SRC:.cpp=.d)}

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

all: ${NAME}

obj/%.o: %.cpp | obj
	$(CC) -c $(CFLAGS) -MMD -MP $(INC) $< -o $@

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
