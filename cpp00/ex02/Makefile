# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 17:06:05 by almounib          #+#    #+#              #
#    Updated: 2024/11/22 00:39:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=
BUILD_DIR	=	build
NAME		=	account
CFLAG		=	-Wall -Wextra -Werror -g3 -std=c++98

SRC			=	tests.cpp Account.cpp
CC			=	g++

OBJ		=	$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o, $(SRC))


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC)	$(CFLAG)	-c	$< -o	$@
	@clear
	
all: $(NAME)

$(NAME):$(OBJ)
	@echo $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAG)
	@clear

clear :
	@clear
	@echo "42 - PARIS : $(NAME)"
	@echo ""

clean : clear
	@rm -rf build/
	@echo "Clean   : ./$(BUILD_DIR) !"

fclean : clean
	@rm -f $(NAME)
	@echo "Clean   : ./$(NAME)"

re: fclean all clear 

.PHONY: all clean fclean re