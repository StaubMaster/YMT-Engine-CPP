
NAME = test.exe
COMPILER = c++

FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
	main.cpp

FILES_OBJ = $(FILES_SRC:.cpp=.o)



ARC_NAME = \
	YMT.a

ARC_DIR = ../

ARC = $(addprefix $(ARC_DIR), $(ARC_NAME))



$(NAME): $(ARC) $(FILES_OBJ)
	$(COMPILER) $(FLAGS) -o $(NAME) $(FILES_OBJ) $(ARC) -lgdi32

all:
	$(MAKE) -C $(ARC_DIR) all
	@$(MAKE) $(FILES_OBJ)
	@$(MAKE) $(NAME)

clean:
	$(MAKE) -C $(ARC_DIR) fclean
	rm -f $(FILES_OBJ)

fclean:
	$(MAKE) -C $(ARC_DIR) clean
	@$(MAKE) clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re



%.o : %.cpp
	$(COMPILER) $(FLAGS) -I ../include -I ../other -c $^ -o $@

$(ARC) :
	@$(MAKE) -C $(ARC_DIR) all


