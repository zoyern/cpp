# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 17:06:05 by almounib          #+#    #+#              #
#    Updated: 2025/09/23 22:24:41 by marvin           ###   ########.fr        #
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
	@echo "╔════════════════════════════════════════════════════════════╗"
	@echo "║                    PMERGEME TESTS SUITE                    ║"
	@echo "╚════════════════════════════════════════════════════════════╝"
	
	@echo "\n=== 1. TESTS BASIQUES ==="
	@echo "Test 1.1: Exemple du sujet"
	./$(NAME) 3 5 9 7 4
	@echo "\nTest 1.2: Tableau simple"
	./$(NAME) 5 2 8 1 9
	@echo "\nTest 1.3: Un seul élément"
	./$(NAME) 42
	@echo "\nTest 1.4: Deux éléments inversés"
	./$(NAME) 2 1
	@echo "\nTest 1.5: Déjà trié"
	./$(NAME) 1 2 3 4 5 6 7 8 9
	@echo "\nTest 1.6: Ordre inverse"
	./$(NAME) 9 8 7 6 5 4 3 2 1
	
	@echo "\n=== 2. TESTS DOUBLONS ==="
	@echo "Test 2.1: Tous identiques"
	./$(NAME) 5 5 5 5 5
	@echo "\nTest 2.2: Paires de doublons"
	./$(NAME) 2 2 3 3 4 4 5 5
	@echo "\nTest 2.3: Doublons mélangés"
	./$(NAME) 3 1 2 3 1 2 3 1 2 3
	@echo "\nTest 2.4: Doublons au début/fin"
	./$(NAME) 1 1 5 3 2 4 4
	
	@echo "\n=== 3. TESTS D'ERREURS ==="
	@echo "Test 3.1: Aucun argument"
	-@./$(NAME) 2>/dev/null && echo "FAIL: Should error" || echo "PASS: Error detected"
	@echo "\nTest 3.2: Nombre négatif"
	-@./$(NAME) -1 2 2>/dev/null && echo "FAIL: Should error" || echo "PASS: Error detected"
	@echo "\nTest 3.3: Zéro (non positif)"
	-@./$(NAME) 0 1 2>/dev/null && echo "FAIL: Should error" || echo "PASS: Error detected"
	@echo "\nTest 3.4: Caractères non numériques"
	-@./$(NAME) a b c 2>/dev/null && echo "FAIL: Should error" || echo "PASS: Error detected"
	@echo "\nTest 3.5: Overflow (> INT_MAX)"
	-@./$(NAME) 2147483648 2>/dev/null && echo "FAIL: Should error" || echo "PASS: Error detected"
	@echo "\nTest 3.6: Nombre avec caractère"
	-@./$(NAME) 12x 2>/dev/null && echo "FAIL: Should error" || echo "PASS: Error detected"
	@echo "\nTest 3.7: Nombre décimal"
	-@./$(NAME) 3.14 2>/dev/null && echo "FAIL: Should error" || echo "PASS: Error detected"
	@echo "\nTest 3.8: Espaces dans le nombre"
	-@./$(NAME) "1 2" 3 2>/dev/null && echo "FAIL: Should error" || echo "PASS: Error detected"
	@echo "\nTest 3.9: Signe plus"
	./$(NAME) +5 +3 +1 +2 +4 || echo "Note: +numbers might not be supported"
	@echo "\nTest 3.10: Leading zeros"
	./$(NAME) 005 003 001 002 004 || echo "Note: Leading zeros might cause issues"
	
	@echo "\n=== 4. TESTS LIMITES ==="
	@echo "Test 4.1: INT_MAX"
	./$(NAME) 2147483647 1 1000
	@echo "\nTest 4.2: Grande plage de valeurs"
	./$(NAME) 1 2147483647 500 1000000 42
	@echo "\nTest 4.3: Beaucoup de petits nombres"
	./$(NAME) 1 1 1 2 2 2 3 3 3 4 4 4 5 5 5
	
	@echo "\n=== 5. TESTS DE TAILLE ==="
	@echo "Test 5.1: 10 éléments"
	./$(NAME) 10 9 8 7 6 5 4 3 2 1
	@echo "\nTest 5.2: 50 éléments aléatoires"
	@./$(NAME) `shuf -i 1-1000 -n 50 | tr "\n" " "`
	@echo "\nTest 5.3: 100 éléments séquentiels"
	@./$(NAME) `seq 100 -1 1`
	@echo "\nTest 5.4: 500 éléments aléatoires"
	@./$(NAME) `shuf -i 1-10000 -n 500 | tr "\n" " "` | head -n 4
	@echo "\nTest 5.5: 1000 éléments aléatoires"
	@./$(NAME) `shuf -i 1-50000 -n 1000 | tr "\n" " "` | head -n 4
	@echo "\nTest 5.6: 3000 éléments (requis par le sujet)"
	@./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "` | head -n 4
	
	@echo "\n=== 6. TESTS PATTERNS SPÉCIAUX ==="
	@echo "Test 6.1: Pattern alterné"
	./$(NAME) 1 100 2 99 3 98 4 97
	@echo "\nTest 6.2: Pattern montagne"
	./$(NAME) 1 3 5 7 9 8 6 4 2
	@echo "\nTest 6.3: Pattern vallée"
	./$(NAME) 9 7 5 3 1 2 4 6 8
	@echo "\nTest 6.4: Beaucoup de doublons aléatoires"
	@./$(NAME) `shuf -r -i 1-10 -n 30 | tr "\n" " "`
	
	@echo "\n=== 7. TESTS DE PERFORMANCE ==="
	@echo "Test 7.1: 100 éléments triés (best case?)"
	@time -p ./$(NAME) `seq 1 100` 2>&1 | grep -E "real|user|sys" || ./$(NAME) `seq 1 100` | tail -n 2
	@echo "\nTest 7.2: 100 éléments inversés (worst case?)"
	@time -p ./$(NAME) `seq 100 -1 1` 2>&1 | grep -E "real|user|sys" || ./$(NAME) `seq 100 -1 1` | tail -n 2
	@echo "\nTest 7.3: 100 éléments aléatoires (average case)"
	@time -p ./$(NAME) `shuf -i 1-1000 -n 100 | tr "\n" " "` 2>&1 | grep -E "real|user|sys" || ./$(NAME) `shuf -i 1-1000 -n 100 | tr "\n" " "` | tail -n 2
	
	@echo "\n=== 8. TESTS VALIDATION FINALE ==="
	@echo "Test 8.1: Vérification du tri (5000 éléments)"
	@./$(NAME) `shuf -i 1-100000 -n 5000 | tr "\n" " "` | grep "After:" | cut -d: -f2 | tr ' ' '\n' | awk 'BEGIN{prev=-1} {if(NF && $$1<=prev){print "FAIL: Not sorted!"; exit 1} prev=$$1} END{print "PASS: Correctly sorted"}'
	@echo "\nTest 8.2: Cohérence vector/deque"
	@./$(NAME) `shuf -i 1-1000 -n 100 | tr "\n" " "` | grep "Time" | awk '{print $$9}' | (read v; read d; echo "Vector: $$v us, Deque: $$d us")
	
	@echo "\n╔════════════════════════════════════════════════════════════╗"
	@echo "║                    TESTS COMPLETED                         ║"
	@echo "╚════════════════════════════════════════════════════════════╝"

# Target pour tests rapides
quick: all
	./$(NAME) 3 5 9 7 4
	./$(NAME) `shuf -i 1-100 -n 20 | tr "\n" " "`
	-./$(NAME) -1 2 2>/dev/null && echo "FAIL" || echo "PASS: Negative detected"
	-./$(NAME) 0 2>/dev/null && echo "FAIL" || echo "PASS: Zero detected"
	-./$(NAME) abc 2>/dev/null && echo "FAIL" || echo "PASS: Non-numeric detected"

# Target pour valgrind
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 5 3 1 4 2
	valgrind --leak-check=full ./$(NAME) `shuf -i 1-100 -n 50 | tr "\n" " "`

# PHONY
.PHONY: all clean fclean re