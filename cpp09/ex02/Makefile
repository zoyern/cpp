# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 17:06:05 by almounib          #+#    #+#              #
#    Updated: 2025/09/23 18:07:22 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = PmergeMe

BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/obj
DEP_DIR     = $(BUILD_DIR)/dep

CC          = c++
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


tests: all
	@echo "=== Tests simples ==="
	./$(NAME) 3 5 9 7 4
	./$(NAME) 5 6 4 9 20 6 44 32 1 56 12 30 60 5
	./$(NAME) 1
	./$(NAME) 2 1
	./$(NAME) 1 2 3 4 5 6 7 8 9
	./$(NAME) 9 8 7 6 5 4 3 2 1
	./$(NAME) 10 10 10 10 10
	./$(NAME) 1 3 3 2 2 4 5 5 5 6
	./$(NAME) 12 3 45 6 7 8 19 1 100 23 23 50 4 4 4 77 2 9

	@echo "\n=== Tests doublons ==="
	./$(NAME) 1 1 1 1 1
	./$(NAME) 2 2 3 3 4 4 5 5
	./$(NAME) 3 1 2 3 1 2 3 1 2 3

	@echo "\n=== Tests erreurs & cas limites ==="
	-./$(NAME)
	-./$(NAME) -1 2
	-./$(NAME) 0 1
	-./$(NAME) a b c
	-./$(NAME) 1 2147483648
	-./$(NAME) 1 2 3 4 x 5

	@echo "\n=== Tests aléatoires (shuf) ==="
	./$(NAME) `shuf -i 1-100 -n 20 | tr "\n" " "`
	./$(NAME) `shuf -i 1-1000 -n 200 | tr "\n" " "`
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`
	./$(NAME) `shuf -r -i 1-50 -n 100 | tr "\n" " "`

	@echo "\n=== Tests limites ==="
	./$(NAME) `seq 1 999`

	./$(NAME) 5 5 5 5 5 1

	./$(NAME) `seq 1 100`
	./$(NAME) `seq 100 -1 1`
	./$(NAME) 1 100 2 99 3 98 4 97
	-./$(NAME) 1 2 x 4 5
	-./$(NAME) 1 2 6x 4 5
	-./$(NAME) 1 2147483648

# PHONY
.PHONY: all clean fclean re