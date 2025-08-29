NAME = btc
SRCS = main.cpp BitcoinExchange.cpp
OBJDIR = Obj
DEPDIR = Dep
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))
DEPS = $(addprefix $(DEPDIR)/,$(SRCS:.cpp=.d))
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

$(NAME) : $(OBJS)
	@printf "\r🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r 🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r  🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r   🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r    🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r     🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r      🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r       🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r        🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r         🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r          🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r           🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r            🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r           🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r          🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r         🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r        🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r       🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r      🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r     🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r    🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r   🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r  🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r 🐆🐆🐆"; \
	sleep 0.08; \
	printf "\r🐆🐆🐆"; \
	sleep 0.08
	@printf "\r                \r"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	

$(OBJDIR)/%.o : %.cpp | $(OBJDIR) $(DEPDIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@
	mv $(OBJDIR)/$(<:.cpp=.d) $(DEPDIR)/

$(OBJDIR) $(DEPDIR):
	mkdir -p $@

all : $(NAME)

clean :
	rm -f $(OBJS) $(DEPS)
	rm -rf $(OBJDIR) $(DEPDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re