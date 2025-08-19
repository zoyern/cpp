# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 17:06:05 by almounib          #+#    #+#              #
#    Updated: 2025/06/03 05:05:16 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = converter

BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/obj
DEP_DIR     = $(BUILD_DIR)/dep

CC          = c++
CFLAG       = -Wall -Wextra -Werror -g3 -std=c++98
DEPFLAG     = -MMD -MP

SRC         = main.cpp ScalarConverter.cpp
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
	@echo "Clean   : ./$(NAME) "

re: fclean all

tests:
	./$(NAME) "0"
	./$(NAME) "42"
	./$(NAME) "-42"
	./$(NAME) "0"
	./$(NAME) "0"
	./$(NAME) "0"
	./$(NAME) "0"
	./$(NAME) "0"
	./$(NAME) "42"
	./$(NAME) "-42"
	./$(NAME) "a"
	./$(NAME) "z"
	./$(NAME) "A"
	./$(NAME) "'r'"
	./$(NAME) "'B'"
	./$(NAME) "' '"
	./$(NAME) "42.0"
	./$(NAME) "42.0f"
	./$(NAME) "-42.2"
	./$(NAME) "42.2f"
	./$(NAME) "nan"
	./$(NAME) "nanf"
	./$(NAME) "+inf"
	./$(NAME) "-inf"
	./$(NAME) "+inff"
	./$(NAME) "-inff"
	./$(NAME) "2147483647" 
	./$(NAME) "-2147483648"  
	./$(NAME) "2147483648"   
	./$(NAME) "-2147483649"
	./$(NAME) ""
	./$(NAME) "42..0"
	./$(NAME) "4.2.2"
	./$(NAME) "--42"
	./$(NAME) "++42"
	./$(NAME) "42.2ff"
	./$(NAME) "f42"
	./$(NAME) "42 42"
	./$(NAME) "42f 42"
	./$(NAME) "-f"
	./$(NAME) "+"
	./$(NAME) "-"
	./$(NAME) "f"
	./$(NAME) "."
	./$(NAME) " "
	./$(NAME) "42f "
	./$(NAME) "42ff"
	./$(NAME) "42fd"
	./$(NAME) "42f d"
	./$(NAME) "42df"
	./$(NAME) " 42f"
	./$(NAME) " 42f "
	./$(NAME) "31"
	./$(NAME) "127"
	./$(NAME) "128"  
	./$(NAME) "0.0f"
	./$(NAME) "-0.0f"
	./$(NAME) "+0.0"
	./$(NAME) "+0.0f"
	./$(NAME) "0."
	./$(NAME) ".0"

# PHONY
.PHONY: all clean fclean re