# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 17:06:05 by almounib          #+#    #+#              #
#    Updated: 2024/12/02 13:33:53 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = cerveau

BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/obj
DEP_DIR     = $(BUILD_DIR)/dep

CC          = g++
CFLAG       = -Wall -Wextra -Werror -g3 -std=c++98
DEPFLAG     = -MMD -MP

SRC         = main.cpp
OBJ         = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
DEP         = $(patsubst %.o, $(DEP_DIR)/%.d, $(OBJ))

-include $(DEP)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAG)
	@echo "Compilation réussie !"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@) $(dir $(DEP_DIR)/$*)
	$(CC) $(CFLAG) $(DEPFLAG) -c $< -o $@
	@mv $(basename $@).d $(DEP_DIR)/$*.d

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Clean   : ./$(BUILD_DIR) !"

fclean: clean
	@rm -f $(NAME)
	@echo "Clean   : ./$(NAME)"

re: fclean all

# PHONY
.PHONY: all clean fclean re