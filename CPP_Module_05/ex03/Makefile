BUILD_DIR	=	build
NAME		=	Intern
CFLAG		=	-Wall -Wextra -Werror -g3 -std=c++98 

SRC			=	main.cpp Bureaucrate.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
			
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