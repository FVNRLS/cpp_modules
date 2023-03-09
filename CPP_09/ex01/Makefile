# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 16:59:51 by rmazurit          #+#    #+#              #
#    Updated: 2023/03/09 17:05:28 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ex01
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

#directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	incl/

SRC_FILES	=	main.cpp \

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

DEP			=	$(wildcard $(INC_DIR)*.hpp) $(wildcard $(INC_DIR)*/*.hpp) Makefile
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(DEP)
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR);

fclean: clean
	rm -f $(NAME);

re: fclean all

.PHONY: all clean fclean re
