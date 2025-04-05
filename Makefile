##
## EPITECH PROJECT, 2025
## JAM-Infinity
## File description:
## Makefile
##

CC              		= 	gcc

NAME         			= 	Infinity

TEST            		= 	units_tests

CFLAGS          		= 	-Wall -Wextra -Werror -Iinclude -g
TEST_CFLAGS     		= 	--coverage -lcriterion

INCLUDE_FLAGS        	= 	-I include/

SRC		          		= 	src/main.c 						\

OBJ          			= 	$(SRC:%.c=obj/%.o)

RED    = \033[1;31m
GREEN  = \033[1;32m
BLUE   = \033[1;34m
NC     = \033[0m

all: obj $(NAME)

obj:
	@mkdir -p obj/src

obj/%.o: %.c | obj
	@echo -e "$(GREEN)Compiling $<...$(NC)"
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE_FLAGS)

$(NAME): $(OBJ)
	@echo -e "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $^ -o $(NAME)

unit_test: $(TEST_OBJ)
	@echo -e "$(BLUE)Compiling unit tests...$(NC)"
	@$(CC) $(TEST_CFLAGS) $^ -o $(TEST)

tests_run: unit_test
	@echo -e "$(BLUE)Running unit tests...$(NC)"
	@./$(TEST)

clean:
	@if [ -d obj ]; then echo -e "$(RED)Cleaning objects.$(NC)"; fi
	@rm -rf obj *.gcda *.gcno

fclean: clean
	@if [ -e "$(NAME)" ]; then echo -e "$(RED)Cleaning $(NAME).$(NC)"; fi
	@if [ -e "$(TEST)" ]; then echo -e "$(RED)Cleaning tests.$(NC)"; fi
	@rm -f $(NAME) $(TEST)

re: fclean all
