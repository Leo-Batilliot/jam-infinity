##
## EPITECH PROJECT, 2025
## JAM-Infinity
## File description:
## Makefile
##

CC              		= 	g++

NAME         			= 	Infinity

TEST            		= 	units_tests

CFLAGS          		= 	-Wall -Wextra -Werror -Iinclude -g
TEST_CFLAGS     		= 	--coverage -lcriterion

INCLUDE_FLAGS        	= 	-I include/ -I include/display

SRC		          		= 	src/main.cpp 									\
						 	src/linked_list/create_node.cpp 				\
						 	src/linked_list/pop_in_linked_list.cpp 			\
						 	src/linked_list/create_linked_list.cpp 			\
						 	src/linked_list/add_in_linked_list.cpp 			\
						 	src/linked_list/destroy_linked_list.cpp 		\
						 	src/linked_list/handle_current_linked_list.cpp 	\
							src/nimadir.cpp 									\
							src/display/Display.cpp 						\
							src/display/Ui.cpp 								\
							src/display/Object.cpp 							\
							src/easter-egg.cpp 								\

OBJ          			= 	$(SRC:%.cpp=obj/%.o)

LIBSFML_FLAGS 			= 	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
NCURSES_FLAGS 		= 	-lncurses

RED    = \033[1;31m
GREEN  = \033[1;32m
BLUE   = \033[1;34m
NC     = \033[0m

all: obj $(NAME)

obj:
	@mkdir -p obj

obj/%.o: %.cpp | obj
	@echo -e "$(GREEN)Compiling $<...$(NC)"
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE_FLAGS)

$(NAME): $(OBJ)
	@echo -e "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $^ -o $(NAME) $(LIBSFML_FLAGS) $(NCURSES_FLAGS) $(CFLAGS) $(INCLUDE_FLAGS)

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
