
NAME = openGL.a

FLAGS = -Wall -Wextra -Werror

FILES_SRC = \
	glad/glad.c

FILES_OBJ = $(FILES_SRC:.c=.o)


$(NAME) :
	ar -rcs $(NAME) $(FILES_OBJ)

all: $(FILES_OBJ) $(NAME)
	@echo '[ all ]'

clean:
	rm -f $(FILES_OBJ)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#c++ $(FLAGS) -o $(NAME) $(FILES_O) $(ARC_OPENGL) $(ARC_FILES) E:/Utility/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a -lgdi32

.PHONY: all clean fclean re



%.o : %.c
	cc $(FLAGS) -c $^ -o $@
