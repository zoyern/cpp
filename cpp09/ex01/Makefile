# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 17:06:05 by almounib          #+#    #+#              #
#    Updated: 2025/08/31 16:22:39 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = RPN

BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/obj
DEP_DIR     = $(BUILD_DIR)/dep

CC          = c++
CFLAG       = -Wall -Wextra -Werror -g3 -std=c++98
DEPFLAG     = -MMD -MP

SRC         = main.cpp RPN.cpp
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

tests: all
	@echo "=== Tests simples ==="
	./$(NAME) "0"
	./$(NAME) "1 2 +"
	./$(NAME) "3 4 *"
	./$(NAME) "9 3 /"
	./$(NAME) "0 3 /"
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "7 7 * 7 -"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	./$(NAME) "3 3 3 + +"
	
	@echo "\n=== Tests erreurs & cas limites ==="
	./$(NAME) "42 55 +"
	./$(NAME) "4 0 /"
	./$(NAME) "1 +"
	./$(NAME) "+"
	./$(NAME) "a b +"          
	./$(NAME) "1 2 &"
	./$(NAME) ""
	./$(NAME) " "
	./$(NAME) "9 9 9 +"


# PHONY
.PHONY: all clean fclean re