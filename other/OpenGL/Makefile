
NAME = openGL.a
FLAGS = -Wall -Wextra -Werror



FILES_SRC = \
	glad/glad.c

FILES_OBJ = $(FILES_SRC:.c=.o)





$(NAME) : $(FILES_OBJ)
	ar -rcs $(NAME) $(FILES_OBJ)

all:
	$(MAKE) $(FILES_OBJ)
	$(MAKE) $(NAME)

clean:
	rm -f $(FILES_OBJ)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re



%.o : %.c
	cc $(FLAGS) -c $^ -o $@
