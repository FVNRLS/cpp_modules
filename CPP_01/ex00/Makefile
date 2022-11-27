# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 13:41:10 by rmazurit          #+#    #+#              #
#    Updated: 2022/11/27 13:47:31 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ex00
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

#directories
PWD			=	$(shell pwd)
SRC_DIR		=	./
OBJ_DIR		=	obj/
INC_DIR		=	./

#controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

#source files
SRC_FILES	=	main.cpp \
				newZombie.cpp \
				randomChump.cpp \
				Zombie.cpp \

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

DEP			=	$(wildcard $(INC_DIR)*.hpp) $(wildcard $(INC_DIR)*/*.hpp) Makefile

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)

#compile the executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(DEP)
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CXX) $(CXXFLAGS) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from $(PWD)...$(RESET)"; else \
	echo "No objects to remove from $(PWD)."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(NAME) from $(PWD)...$(RESET)"; else \
	echo "No Executable to remove from $(PWD)."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re run