
NAME = main.exe
COMPILER = c++

FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
	main.cpp

FILES_OBJ = $(FILES_SRC:.cpp=.o)



ARC_NAME = \
	YMT.a

ARC_DIR = ../

ARC = $(addprefix $(ARC_DIR), $(ARC_NAME))



$(NAME): $(ARC)
	$(COMPILER) $(FLAGS) -o $(NAME) $(ARC) -lgdi32

all:
	@$(MAKE) $(addprefix $(DIR_OBJ), $(FILES_OBJ))
	@$(MAKE) $(NAME)

clean:
	rm -f $(addprefix $(DIR_OBJ), $(FILES_OBJ))

fclean:
	@$(MAKE) clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re



%.o : %.cpp
	$(COMPILER) $(FLAGS) -c $^ -o $@

$(ARC) :
	@$(MAKE) -C $(ARC_DIR) all


